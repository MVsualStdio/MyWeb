#ifndef TCPSERVER_H
#define TCPSERVER_H

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
#include "./Epolloop.hpp"
#include "./Connectserver.hpp"
#include "unordered_map"
#include <mutex>
#include "IMuduoUser.hpp"
namespace Net{
    class Tcpserver : public ServerIO{
        #define MAX_EVENTS 500
        #define MAX_LISTEN_FD 5
        #define LISTEN_PORT 6868
        #define THREAD_NUM 2
        #define SOCKET_CREATE_ERROR -10
        #define EPOLL_ERROR -11

        public:
            Tcpserver(std::shared_ptr<Epolloop> eloop);
            void Tcpinit();
            ~Tcpserver();
            void serverRead();
            void serverWrite();
            void serverClose(){};
            void setUser(IMuduoUser* _user){user = _user;};
        private:
            std::shared_ptr<Epolloop> conloop[2];
            std::thread loopThread[2];
            std::unordered_map<int,std::shared_ptr<Connectserver>> conList;
            int createSocket();
            int socketfd;
            std::shared_ptr<Epolloop> loop;
            Net::Channel* channel; 
            IMuduoUser* user; 
            // static std::thread::id mainThreadId;
    };
}

#endif