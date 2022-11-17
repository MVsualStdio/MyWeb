
#include "../include/WebServer.hpp"
using namespace std;
using namespace Net;
using namespace web;


std::shared_ptr<Net::HttpResponse> WebSever::onRequest(const HttpRequest& req){
    LogDebug << "Headers " << req.methodString() << " " << req.path();
    string path = req.path();
    if(route_.isExistRoute(path)){
        ResponseCall::Ptr s =  route_.getResponse(path);
        const std::string& connection = req.getHeader("Connection");
        bool close = connection == "close" ||
            (req.getVersion() == HttpRequest::kHttp10 && connection != "Keep-Alive");
        std::shared_ptr<Net::HttpResponse> Newresp =  s->ResRun(req);
        Newresp->setCloseConnect(close);
        return Newresp;
    }
    else{
        ResponseCall::Ptr s =  route_.getResponse("/404/");
        const std::string& connection = req.getHeader("Connection");
        bool close = connection == "close" ||
            (req.getVersion() == HttpRequest::kHttp10 && connection != "Keep-Alive");
        std::shared_ptr<Net::HttpResponse> Newresp =  s->ResRun(req);
        Newresp->setCloseConnect(close);
        return Newresp;
    }
    return nullptr;
}

WebSever::WebSever(){
    Net::Logger::instance()->logInit(Config::LogDir,Config::LogCount);
}

void WebSever::start(){
    
    std::shared_ptr<Net::Epolloop> loop(new Net::Epolloop());
    Net::HttpServer server(loop,Config::port,Config::numThread,Config::BufferMaxLen);
    server.setHttpCallback(std::bind(&WebSever::onRequest,this,std::placeholders::_1));
    
    server.start();
    server.loop();
}

void WebSever::addRoute(string path, ResponseCall::Ptr res){
    route_.addRoute(path,res);
}

    
