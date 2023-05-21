#include "Connectserver.hpp"


using namespace Net;


Connectserver::Connectserver(int fd,std::shared_ptr<Epolloop> eloop,std::shared_ptr<TimerManger>timeManger):
    socketfd(fd),timeManger_(timeManger){
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
    std::shared_ptr<Task> task(new Task(&Connectserver::serverClose,this));
    std::shared_ptr<TimeStamp> timeStamp(new TimeStamp(chrono::seconds(10),move(task),30,socketfd));
    timeManger_->addTimer(timeStamp);
}

Connectserver::~Connectserver(){
    delete(channel);
}

void Connectserver::serverClose(){
    LogMessage << socketfd << " is closed";
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
    if(length && user){
        user->onMessage(this,&buffer);
    }   
    else{
       serverClose();
    }
}