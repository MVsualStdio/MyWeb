#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include <iostream>
#include <arpa/inet.h>
#include <fcntl.h>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include "../Logger/Logger.hpp"
#include "./ServerIO.hpp"
#include "./Channel.hpp"
#include "./Epoll.hpp"
#include "./Epolloop.hpp"
#include "Channel.hpp"
#include "../Buffer/Buffer.hpp"
#include "IMuduoUser.hpp"
#include "../Http/HttpContext.hpp"
#include "../Timer/TimerManger.hpp"

namespace Net{
    class Tcpserver;
    class Connectserver : public ServerIO{
        #define MAX_LINE 65535
        public:
            explicit Connectserver(std::string ip,int port,int fd,std::shared_ptr<Epolloop> eloop,std::shared_ptr<TimerManger> timeManger);
            ~Connectserver();
            virtual void serverRead();
            virtual void serverWrite();
            int getFd(){ return socketfd;}
            std::string getIp(){return ip;}
            int getPort(){return port;}
            void serverClose();
            void Coninit();
            std::shared_ptr<HttpContext> getHttpState(){return state;};
            void setHttpState(std::shared_ptr<HttpContext> state_){state =  state_;};
            void setUser(IMuduoUser* _user){user = _user;}
            void connectEstablished();
            Net::Channel *getChannel(){return channel;}
        private:
            std::shared_ptr<HttpContext> state;
            int socketfd;
            std::shared_ptr<Epolloop> loop;
            Net::Channel* channel; 
            IMuduoUser* user;
            Buffer buffer;
            std::shared_ptr<TimerManger> timeManger_;
            std::string ip;
            int port;
    };
}

#endif