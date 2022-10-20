#ifndef EPOLLOOP_H
#define EPOLLOOP_H

#include "Epoll.hpp"
#include "Channel.hpp"
#include "../Queue/Queue.hpp"

namespace Net{

    class Epolloop: public enable_shared_from_this<Epolloop>{
        public:
            using Functor = std::function<void (void)>;
        private:
            std::unique_ptr<Epoll> epoll;
            std::thread::id _th_id;
            Queue<Functor> FunctorList;
        public:
            void loop();
            Epolloop();
            ~Epolloop();
            void update(Channel* channel);
            void delChannel(Channel* channel);
            void runInThread(Functor fun);
            void ThreadFun();
            //void addFd(Channel& Channel);
    };

}

#endif