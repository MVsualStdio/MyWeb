#ifndef HTTPSERVER_H
#define HTPPSERVER_H

#include "../Socket/Tcpserver.hpp"
#include "HttpContext.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

namespace Net{
    class HttpServer:public Net::IMuduoUser{
        public:
            using  HttpCallback = std::function<std::shared_ptr<Net::HttpResponse> (const HttpRequest&)>;

        private:
            std::shared_ptr<Net::Tcpserver> tcp_;
            HttpCallback httpCallback_;
            std::shared_ptr<Epolloop> loop_;
        public:
            virtual void onConnection(Connectserver* pCon);
            virtual void onMessage(Connectserver* pCon, Buffer* pBuf);
            virtual void onWriteComplate(Connectserver* pCon);
            HttpServer(std::shared_ptr<Epolloop>);
            void start();
            void loop();
            void setHttpCallback(const HttpCallback& httpCallback){httpCallback_ = httpCallback;}
            ~HttpServer();
        private:
           
            void onRequest(Connectserver*, const HttpRequest&);
    };
}





#endif