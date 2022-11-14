#include "HttpServer.hpp"



using namespace Net;

HttpServer::HttpServer(std::shared_ptr<Epolloop> loop,int port,int numthread,int listLen):loop_(loop),hopeMaxLen(listLen){
    tcp_ = std::make_shared<Tcpserver>(loop,port,numthread);
}

HttpServer::~HttpServer(){

}

void HttpServer::start(){
    tcp_->setUser(this);
    tcp_->Tcpinit();
}

void HttpServer::onConnection(Connectserver* pCon){

}

void HttpServer::onWriteComplate(Connectserver* pCon){

}

void HttpServer::onMessage(Connectserver* pCon, Buffer* pBuf){
    std::shared_ptr<HttpContext> context = pCon->getHttpState();
    if(!context){
        context = std::make_shared<HttpContext>();
        pCon->setHttpState(context);
    }
    int ok = context->parseRequest(pBuf);
    if(!ok){
        pCon->serverClose();
    }
    else if(context->state()==HttpContext::HttpRequestParseState::kGotAll){
        onRequest(pCon, context->request());
        context->reset();
    }
    
    // else{
    //     std::cout<<"parse continue"<<std::endl;
    // }
    // std::cout<<std::this_thread::get_id()<<"    Http res"<<std::endl;
}

void HttpServer::onRequest(Connectserver* pCon, const HttpRequest& req){
    std::shared_ptr<Net::HttpResponse> response =  httpCallback_(req);
    if(response){
        std::list<std::shared_ptr<Buffer>> bufs;
        response->toBuffer(bufs,hopeMaxLen);
        for(auto& buf : bufs ){
            buf->writeConnect(pCon);
        }

        if (response->closeConnection()){
            pCon->serverClose();
        }
    }

}

void HttpServer::loop(){
    loop_->loop();
}

