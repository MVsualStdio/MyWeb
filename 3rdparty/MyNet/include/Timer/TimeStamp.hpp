#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include "../Task/WorkItem.hpp"
#include "../ThreadPool/ThreadPool.hpp"
#include <chrono>
#include <thread>
#include <memory>
#include <functional>
#include <utility>
#include <iostream>
#include <mutex>
#include <iostream>
#include <queue>
#include <condition_variable>

namespace Net{
    using namespace std;
    class TimeStamp{
        public:
            // TimeStamp(chrono::time_point<chrono::high_resolution_clock> secondsTime,shared_ptr<WorkItem> task):\
            //         _secondsTime(secondsTime),_duration(0),_task(move(task)){
            // }
            TimeStamp(chrono::seconds duration,shared_ptr<WorkItem> task,int count,int fd):\
                    _task(move(task)),_duration(duration),_count(count),_fd(fd){
                    _secondsTime = chrono::high_resolution_clock::now() + _duration;
            }

            // TimeStamp(const TimeStamp& timestamp){
            //     this->_duration =  timestamp._duration;
            //     this->_secondsTime = timestamp._secondsTime;
            //     this->_task = timestamp._task;
            //     if(_task == nullptr){
            //         cout<<"copy null"<<endl;
            //     }
            // }

            bool operator<(const TimeStamp& b) const { return _secondsTime > b._secondsTime; }

            chrono::time_point<chrono::high_resolution_clock> getTimePoint(){
                return _secondsTime;
            }

            chrono::seconds getDuration(){
                return _duration;
            }

            shared_ptr<WorkItem> getTask(){
                return _task;
            }     
            
            int getCount(){
                return _count;
            }

            int getFd(){
                return _fd;
            }
            
            void setDuration(chrono::seconds duration){
                _duration = duration;
            }
        private:
            chrono::time_point<chrono::high_resolution_clock> _secondsTime;
            chrono::seconds _duration;
            shared_ptr<WorkItem> _task;
            int _fd;
            int _count;
    };
}

#endif