#include "Connectserver.hpp"


using namespace Net;


Connectserver::Connectserver(int fd,std::shared_ptr<Epolloop> eloop):
    socketfd(fd){
        loop = eloop;
        channel = new Channel(loop,socketfd);
        user = nullptr;
}

void Connectserver::connectEstablished(){
    if(user){
        user->onConnection(this);
    }
}



void Connectserver::Coninit(){
    channel->setCallBack(this);
    channel->enableReading();
}

Connectserver::~Connectserver(){
    delete(channel);
}

void Connectserver::serverClose(){
    if(channel){
        loop->delChannel(channel);
    }
    close(socketfd);
    
}

void Connectserver::serverWrite(){
    buffer.writeConnect(this);  
    channel->setEvent(EPOLLONESHOT | EPOLLRDHUP);
    channel->enableReading();
    channel->disableWriting();
}



void Connectserver::serverRead(){

    int length = buffer.readConnect(this);
    // std::cout<<buffer.peek()<<std::endl;
    // std::cout<<length<<std::endl;
    if(length){
        if(user){
            user->onMessage(this,&buffer);
        }
    }   
    else{
       serverClose();
    }
}