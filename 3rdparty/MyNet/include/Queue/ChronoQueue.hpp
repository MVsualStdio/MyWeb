#ifndef CHRONOQUEUE_H
#define CHRONOQUEUE_H

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
            TimeStamp(chrono::time_point<chrono::high_resolution_clock> secondsTime,shared_ptr<WorkItem> task):\
                    _secondsTime(secondsTime),_duration(0),_task(move(task)){
            }
            TimeStamp(chrono::time_point<chrono::high_resolution_clock> secondsTime,shared_ptr<WorkItem> task,chrono::seconds duration):\
                    _secondsTime(secondsTime),_task(move(task)),_duration(duration){
            }

            // TimeStamp(TimeStamp&& timestamp){
            //     this->_duration =  move(timestamp._duration);
            //     this->_secondsTime = move(timestamp._secondsTime);
            //     this->_task = move(timestamp._task);
            //     timestamp = nullptr;
            //     if(_task == nullptr){
            //         cout<<"copy null"<<endl;
            //     }
            // }

             TimeStamp(const TimeStamp& timestamp){
                this->_duration =  timestamp._duration;
                this->_secondsTime = timestamp._secondsTime;
                this->_task = timestamp._task;
                if(_task == nullptr){
                    cout<<"copy null"<<endl;
                }
            }


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
            
        private:
            chrono::time_point<chrono::high_resolution_clock> _secondsTime;
            chrono::seconds _duration;
            shared_ptr<WorkItem> _task;
    };

    class ChronoQueue{
        public:
            ChronoQueue();
            ~ChronoQueue();
            void chronoPush(TimeStamp timestamp);
        private:
            void popRun();
            void taskRun(TimeStamp stamp);
            bool _run;
            mutex _mutex;
            condition_variable _cond;
            queue<TimeStamp> _queue;
            thread th[3];
    };


    ChronoQueue::ChronoQueue(){
            _run = 1;
            std::thread([this]() { popRun(); }).detach();
            // for(int i=0;i<3;++i){
            //     
            // }
    }

    ChronoQueue::~ChronoQueue(){
            _run = 0;
            _cond.notify_all();
            // for(int i=0;i<3;++i){
            //     th[i].join();
            // }
    }

    void ChronoQueue::chronoPush(TimeStamp item){
        // cout<<"push right"<<endl;
        unique_lock<mutex> locker(_mutex);
        _queue.push(forward<TimeStamp>(item));
        _cond.notify_all();
    }

    void ChronoQueue::taskRun(TimeStamp stamp){
        shared_ptr<WorkItem> _task = stamp.getTask();
        if(_task == nullptr){
            cout<<"error"<<endl;
        }
        _task->run();
        
    }

    void ChronoQueue::popRun(){
        while(_run){
            unique_lock<mutex> locker(_mutex);
            while(_queue.empty()){
                _cond.wait(locker);
                continue;
            }
            TimeStamp temp =  _queue.front();
            auto diff = temp.getTimePoint() - chrono::high_resolution_clock::now();
            if(chrono::duration_cast<chrono::milliseconds>(diff).count()>0){
                _cond.wait_for(locker,diff);
                continue;
            }
            else{
                // if(temp.getDuration().count()>0){
                //     chrono::time_point<chrono::high_resolution_clock> stap;
                //     stap = chrono::high_resolution_clock:now() + tem.getDuration();
                //     TimeStamp newtemp(stop,task);
                //     chronoPush(temp);
                // }
                _queue.pop();
                ThreadPool::instance()->addTask(temp.getTask());
            }
        }
    }
}

#endif