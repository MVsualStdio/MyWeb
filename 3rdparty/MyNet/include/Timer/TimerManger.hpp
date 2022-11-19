#ifndef TIMERMANGER_H
#define TIMERMANGER_H
// #include "../Socket/ServerIO.hpp"
#include "TimeStamp.hpp"
#include <list>

namespace Net{
    class TimerManger{
        private:
            
            list<std::shared_ptr<TimeStamp>>  timePool; 
            //list<TimeStamp>  timePool; 

            mutex _mutex;
            condition_variable _cond;
            void workTask();
            void waitTask();
        public:
            TimerManger();
            void initTime();
            void addTimer(std::shared_ptr<TimeStamp> stamp);
    };
}


#endif