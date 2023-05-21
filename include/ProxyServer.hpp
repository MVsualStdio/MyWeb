#ifndef PROXYSERVER_H
#define PROXYSERVER_H

#include "Response.hpp"
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
#include "WebServer.hpp"
using namespace std;

namespace web{
    class ProxyNode : public Net::HttpServer{
        public:
            ProxyNode(std::shared_ptr<Epolloop> epoll,int port,int numthread,int listLen):HttpServer(epoll,port,numthread,listLen){
                
            }

            virtual void onRequest(Connectserver* pCon, const HttpRequest& req) override{
                std::unordered_map<int,std::shared_ptr<Connectserver>> Connects = tcp_->getConList();

                std::shared_ptr<Net::HttpResponse> response =  httpCallback_(req);
            
                for(auto Connect:Connects){
                    if(response){
                        std::list<std::shared_ptr<Buffer>> bufs;
                        response->toBuffer(bufs,hopeMaxLen);
                        for(auto& buf : bufs ){
                            buf->writeConnect(Connect.second.get());
                        }
                        if (response->closeConnection()){
                            pCon->serverClose();
                        }
                    }
                }
            }
            // void addSouce(string dir);
             
    };

    class ProxyServer: public web::WebSever{
        public:
            void start(){
                std::shared_ptr<Net::Epolloop> loop(new Net::Epolloop());
                web::ProxyNode server(loop,Config::port,Config::numThread,Config::BufferMaxLen);
                server.setHttpCallback(std::bind(&WebSever::onRequest,this,std::placeholders::_1));
                
                server.start();
                server.loop();
            }
    };
}



#endif