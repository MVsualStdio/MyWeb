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
#include "Buffer/Buffer.hpp"
#include <list>

using namespace std;

namespace web{

    class ProxyNode : public Net::HttpServer{
        private:
            int HostFd;
            // int my_read(int fd,void *buffer,int length) { 
            //     int bytes_left; 
            //     int bytes_read; 
            //     char *ptr; 
            //     bytes_left=length; 
            //     while(bytes_left>0) 
            //     { 
            //         bytes_read=read(fd,ptr,bytes_read); 
            //         if(bytes_read<0) 
            //         { 
            //         if(errno==EINTR) 
            //             bytes_read=0; 
            //         else 
            //             return(-1); 
            //         } 
            //         else if(bytes_read==0) 
            //             break; 
            //         bytes_left-=bytes_read; 
            //         ptr+=bytes_read; 
            //     } 
            //     return(length-bytes_left); 
            // }
        public:
            ProxyNode(std::shared_ptr<Epolloop> epoll,int port,int numthread,int listLen):HttpServer(epoll,port,numthread,listLen){

                HostFd = socket(AF_INET, SOCK_STREAM, 0);
                struct sockaddr_in serv_addr;
                memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
                serv_addr.sin_family = AF_INET;  //使用IPv4地址
                serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
                serv_addr.sin_port = htons(6868);  //端口
                connect(HostFd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
                cout<<"=============cc==============="<<endl;
            }

            virtual void onMessage(Connectserver* pCon, Buffer* pBuf) override{
                
                cout<<"send to Host...  "<<string(pBuf->peek())<<endl;
                int l = pBuf->writeFd(HostFd);
                //cout<<"send Len:"<<l<<endl;
                cout<<"================================="<<endl;
                //do{
                std::shared_ptr<Buffer> bufRecive = make_shared<Buffer>(); 
                l = bufRecive->readFd(HostFd);
                cout<<"recive from Host...  Len:"<<l<<endl;
                cout<<string(bufRecive->peek(),17)<<endl;
                l = bufRecive->writeConnect(pCon);
                cout<<"send to Client...  Len:"<<l<<endl;
                //}while(l >= 4096);
                cout<<"================end==============="<<endl;
            }

             
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