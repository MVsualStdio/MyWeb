#ifndef CHANNEL_H
#define CHANNEL_H

#include<memory>
#include<utility>
#include <sys/epoll.h>
#include "ServerIO.hpp"  

namespace Net{
    class Epolloop;
    class Channel{ 
        public:
            Channel(std::shared_ptr<Epolloop> eloop, int socket);
            ~Channel() = default;
            void setEvent(uint32_t event);
            void setReEvent(uint32_t reevent);
            void ChannelCallback();
            void setCallBack(ServerIO* serverio);
            int getFd() const;
            void update();
            uint32_t getEvent()const;
            uint32_t getReEvent()const;
            int getIndex(){return index;}
            void setIndex(int _index){index = _index;}
            void enableReading(){event |= EPOLLIN; update();}
            void enableWriting(){event |= EPOLLOUT; update();}
            void disableWriting(){event &= !EPOLLOUT;update();}
            void etModel(){event |= EPOLLET; update();}
        private:
            int index;
            uint32_t reevent;
            uint32_t event;
            ServerIO* serverio;
            int socket_fd;
            std::shared_ptr<Epolloop> loop;
    };
} // namespace Net

#endif