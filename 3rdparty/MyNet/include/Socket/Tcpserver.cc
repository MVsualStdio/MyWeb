
#include "Tcpserver.hpp"

using namespace Net;
//std::thread::id Tcpserver::mainThreadId;
Tcpserver::Tcpserver(std::shared_ptr<Epolloop> eloop):
    loop(eloop){
        socketfd = createSocket();
        channel = new Channel(loop,socketfd);
        user = nullptr;
        for(int i=0;i<THREAD_NUM;++i){
            conloop[i] = std::make_shared<Epolloop>();
        }
        
    }



void Tcpserver::Tcpinit(){
    channel->setCallBack(this);
    channel->enableReading();
    for(int i=0;i<THREAD_NUM;++i){
        loopThread[i] = std::move(std::thread(&Epolloop::loop,conloop[i]));
    }
    
}



Tcpserver::~Tcpserver(){
    delete(channel);
}



void Tcpserver::serverWrite(){
    std::cout<<"tcpwrite"<<std::endl;
}

void Tcpserver::serverRead(){
    sockaddr_in client_addr;
    bzero(&client_addr, sizeof(client_addr));
    int client_len = sizeof(client_addr);
    int conn_fd = accept(socketfd, (sockaddr*)&client_addr, (socklen_t*)&client_len);
    if(conn_fd > 0) {
        LogDebug(Net::Logger::MESSAGE) << "New Connection from: ["
                    << inet_ntoa(client_addr.sin_addr) << ':'
                    << ntohs(client_addr.sin_port) <<']'
                    << " accepted, Socket ID: "
                    << conn_fd;
        fcntl(conn_fd, F_SETFL, O_NONBLOCK);
        conList[conn_fd] = std::shared_ptr<Connectserver>(new Connectserver(conn_fd,conloop[rand()%THREAD_NUM]));
        conList[conn_fd]->Coninit();
        conList[conn_fd]->setUser(user);
        conList[conn_fd]->connectEstablished(); 
    } 
    else {
        LogDebug(Net::Logger::MESSAGE) <<  "accept error, errno" << errno;
    }

}




int Tcpserver::createSocket(){
    int socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(socketfd == -1){
        LogDebug(Net::Logger::WARN) << "socket create error";
    }
    fcntl(socketfd,F_SETFL,O_NONBLOCK);
    int opt = 1;
    setsockopt(socketfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(LISTEN_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(socketfd,(sockaddr*)&server_addr,sizeof(server_addr));
    if(ret == -1){
        LogDebug(Net::Logger::WARN) << "socket bind error";
    }
    ret = listen(socketfd,MAX_LISTEN_FD);
    if( ret == -1){
        LogDebug(Net::Logger::WARN) << "socket listen error";
    }
    return socketfd;
}