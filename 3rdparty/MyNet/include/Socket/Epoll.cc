
#include "Epoll.hpp"

using namespace Net;

Epoll::Epoll():_events(512){
    _eventFd = epoll_create(EPOLL_NUM);
    
}

Epoll::~Epoll(){
}

// bool Epoll::addFd(Channel* channel){
//     int fd = channel->getFd();
//     uint32_t event = channel->getEvent();
//     if(fd < 0){
//         return false;
//     }
//     epoll_event ev = {0};
//     ev.data.fd = fd;
//     ev.events = event;
//     ev.data.ptr = channel;
//     return epoll_ctl(_eventFd,EPOLL_CTL_ADD,fd,&ev) == 0;
// }

bool Epoll::addFd(Channel* channel){
    int fd = channel->getFd();
    if(fd < 0){
        return false;
    }
    epoll_event ev = {0};
    ev.data.fd = fd;
    ev.events = channel->getEvent();
    ev.data.ptr = channel;
    return epoll_ctl(_eventFd,EPOLL_CTL_ADD,fd,&ev) == 0;
}

// void Epoll::wait(std::vector<Channel *>& channels,int timeoutMs){
//     int fds = epoll_wait(_eventFd,&_events[0],static_cast<int>(_events.size()),timeoutMs);
//         for(int i = 0; i < fds; i++) {
//             Channel* pChannel = static_cast<Channel*>(_events[i].data.ptr);
//             pChannel->setEvent(_events[i].events);
//             channels.push_back(pChannel);
//     }
// }

void Epoll::wait(std::vector<Channel*>& channels,int time){
    int count = epoll_wait(_eventFd,&_events[0],static_cast<int>(_events.size()),time);
    
        for (int i = 0; i < count; i++) {
            epoll_event cur_event = _events[i];
            int fd = cur_event.data.fd;
            Channel* cur_chan =  (Channel*)cur_event.data.ptr;
            if (cur_chan) {
                cur_chan->setReEvent(cur_event.events);
                channels.emplace_back(cur_chan);
            } 
            else {
                LogDebug(Net::Logger::MESSAGE) <<"fd" << fd << "not exist in fd2chan_";
            }
  }
}



bool Epoll::delFd(Channel* channel){
    int fd = channel->getFd();
    if(fd < 0) {
        return false;
    }
    epoll_event ev = {0};
    return 0 == epoll_ctl(_eventFd, EPOLL_CTL_DEL, fd, &ev);
}

bool Epoll::modFd(Channel* channel){
    int fd = channel->getFd();
    if(fd < 0) {
        return false;
    }
    epoll_event ev = {0};
    ev.data.fd = fd;
    ev.events = channel->getEvent();
    return 0 == epoll_ctl(_eventFd, EPOLL_CTL_MOD, fd, &ev);
}

int Epoll::GetEventFd(size_t i) const{
    return _events[i].data.fd;
}
uint32_t Epoll::GetEvents(size_t i) const{
    return _events[i].events;
}

void Epoll::update(Channel* channel){
    int index = channel->getIndex();
    if(index == -1){
        channel->setIndex(1);
        addFd(channel);
    }
    else{
        modFd(channel);
    }
}