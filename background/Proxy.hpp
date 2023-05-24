#ifndef PROXY_H
#define PROXY_H
#include "Route.hpp"
#include "Render.hpp"
#include "Http/HttpRequest.hpp"
#include "RenderPool.hpp"
#include "MysqlPool.hpp"
#include <nlohmann/json.hpp>
#include <arpa/inet.h>
#include "WebConfig.hpp"
using json = nlohmann::json;

namespace web{
    using namespace Net;

    class ProxyHost{
        private:
            int sock;
        public:
            ProxyHost(const string& ip,const int port){
                sock = ::socket(AF_INET, SOCK_STREAM, 0);

                //向服务器（特定的IP和端口）发起请求
                struct sockaddr_in serv_addr;
                memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
                serv_addr.sin_family = AF_INET;  //使用IPv4地址
                serv_addr.sin_addr.s_addr = inet_addr(ip.c_str());  //具体的IP地址
                serv_addr.sin_port = htons(port);  //端口
                if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))){
                    cout<<"Connect Proxy: "<<ip.c_str()<<":"<<to_string(port)<<endl;
                }
                
            }
            ~ProxyHost(){
                ::close(sock);
            }
            int getSocket(){
                return sock;
            }
    };

    class Proxy: public web::ResponseCall{
        private:
           std::shared_ptr<ProxyHost> Host; 
           
        public:
            static ResponseCall::Ptr newPtr(){
                return std::shared_ptr<Proxy>(new Proxy());
            }

            void ProxyInitHost(const string& ip,const int port){
                Host = std::make_shared<ProxyHost>(ip,port);
            }

            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest req){
                int sock = socket(AF_INET, SOCK_STREAM, 0);

                //向服务器（特定的IP和端口）发起请求
                struct sockaddr_in serv_addr;
                memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
                serv_addr.sin_family = AF_INET;  //使用IPv4地址
                serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
                serv_addr.sin_port = htons(6868);  //端口

                connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

                char buffer[65536] = "GET /proxy HTTP/1.1\r\n"
                    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\r\n"
                    "Accept-Encoding: gzip, deflate\r\n"
                    "Accept-Language: zh-CN,zh;q=0.9\r\n"
                    "Cache-Control: max-age=0\r\n"
                    "Host: 81.70.1.235:6869\r\n"
                    "Upgrade-Insecure-Requests: 1\r\n"
                    "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36\r\n\r\n";
                write(sock, buffer, sizeof(buffer)-1);
                char newbuffer[65536];
                read(sock, newbuffer, sizeof(newbuffer)-1);
                printf("Message form server: %s\n", newbuffer);
                
            
                //关闭套接字
                close(sock);
                return nullptr;
                // std::list<std::shared_ptr<Buffer>> buffers;
                // // req.setPath("/");
                // req.toBuffer(buffers,Config::BufferMaxLen);
                // //cout<<buffers.size()<<endl;

                // // req.addHeader("Referer","http://81.70.1.235:6869/"); 
                // for(auto buf: buffers){
                //     cout<<buf->peek()<<endl;
                // }

                // string sendContent = "";
                // if(Host){
                //     std::shared_ptr<Buffer> ReadBuffer = std::make_shared<Buffer>();
                //     int len = 0;
                //         char line[65536];
                //         // cout<<buf->peek()<<endl;
                //         // len = buf->writeFd(Host->getSocket());
                //         // cout<<len<<endl;
                //         char buffer[65536] = "GET /proxy HTTP/1.1\r\n"
                //             "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\r\n"
                //             "Accept-Encoding: gzip, deflate\r\n"
                //             "Accept-Language: zh-CN,zh;q=0.9\r\n"
                //             "Cache-Control: max-age=0\r\n"
                //             "Host: 81.70.1.235:6869\r\n"
                //             "Upgrade-Insecure-Requests: 1\r\n"
                //             "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36\r\n\r\n";
                //         write(Host->getSocket(), line, sizeof(line)-1);
                //         cout<<"=================="<<endl;

                //         // len = ReadBuffer->readFd(Host->getSocket());
                //         // cout<<len<<endl;
                //         // sendContent.append(buf->peek());
        
                        
                //         ssize_t read_length = ::read(Host->getSocket(), line, sizeof(line)-1);
                //         // std::cout<<"readfd"<<read_length<<std::endl;
                    
                    
                //     cout<<sendContent<<endl;
                //     return GetRender->SendContent(sendContent,RenderType::ResponseType::text);
                // }

                // // std::shared_ptr<Net::HttpResponse> res;
                // return nullptr;
            }
    };

}

#endif