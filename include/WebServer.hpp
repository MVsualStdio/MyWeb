#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Response.hpp"
#include "Http/HttpServer.hpp"
#include "Socket/Epolloop.hpp"
#include "Route.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <sys/mman.h>
#include <fcntl.h>
#include <regex>
#include "RenderPool.hpp"
#include "WebConfig.hpp"
using namespace std;
using namespace Net;


namespace web{
    class WebSever{
        public:
        private:
            Route route_;
            std::shared_ptr<Net::HttpResponse> onRequest(const HttpRequest& req){
                std::cout << "Headers " << req.methodString() << " " << req.path() << std::endl;
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
        public:
            WebSever() = default;
            void start(){
                
                std::shared_ptr<Net::Epolloop> loop(new Net::Epolloop());
                 
                Net::HttpServer server(loop,Config::port,Config::numThread,Config::BufferMaxLen);
                server.setHttpCallback(std::bind(&WebSever::onRequest,this,std::placeholders::_1));
               
                server.start();
                server.loop();
            }
            void addRoute(string path, ResponseCall::Ptr res){
                route_.addRoute(path,res);
            }
            void addSouce(string dir){
                route_.addSourceDir(dir);
            }
    };
}

#endif