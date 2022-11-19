
#include "Tcpserver.hpp"
#include "Epolloop.hpp"

using namespace Net;

Epolloop::Epolloop(){
    epoll = move(std::unique_ptr<Epoll>(new Epoll()));
}

Epolloop::~Epolloop(){

}
 


void Epolloop::loop(){
    while(1){
        std::vector<Net::Channel*> channels;
        epoll->wait(channels,1000);
        for(Net::Channel* c : channels){
            c->ChannelCallback();
            //std::cout<<std::this_thread::get_id()<<std::endl;
        }
    }
}

void Epolloop::update(Channel* channel){
    epoll->update(channel);
}

void Epolloop::delChannel(Channel* channel){
    epoll->delFd(channel);
}

// void Epolloop::addFd(Channel& channel){
//     epoll.addFd(channel);
// }