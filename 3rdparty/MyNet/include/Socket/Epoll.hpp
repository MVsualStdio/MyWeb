#ifndef EPOOL_H
#define EPOOL_H

#include <sys/epoll.h> //epoll_ctl()
#include <fcntl.h>  // fcntl()
#include <unistd.h> // close()
#include <assert.h> // close()
#include <vector>
#include <errno.h>
#include "Channel.hpp"
#include "../Logger/Logger.hpp"

namespace Net{
    #define EPOLL_NUM 1024
    using namespace std;
    class Epoll{
        private:
            vector<epoll_event> _events;
            int _eventFd;
        public:
            Epoll();
            // bool addFd(Channel* channel);
            bool addFd(Channel* channel);
            bool modFd(Channel* channel);
            bool delFd(Channel* channel);
            void update(Channel* channel);
            void wait(std::vector<Channel*>& channels,int time = -1);
            int GetEventFd(size_t i) const;
            uint32_t GetEvents(size_t i) const;
            ~Epoll();
        };
}




#endif