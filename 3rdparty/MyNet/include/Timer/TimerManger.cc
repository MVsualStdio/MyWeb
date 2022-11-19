#include "TimerManger.hpp"
#include "../Socket/Connectserver.hpp"
#include <sys/timerfd.h>

using namespace Net;


TimerManger::TimerManger(){

}

void TimerManger::initTime(){
    std::shared_ptr<Task> task(new Task(&TimerManger::waitTask, this));
    ThreadPool::instance()->addTask(move(task));
}



void TimerManger::addTimer(std::shared_ptr<TimeStamp> stamp){
    std::unique_lock<mutex> locker(_mutex);
    auto it = timePool.begin();
    for(;it!=timePool.end();++it){
        if((*it)->getFd() == stamp->getCount()){
            (*it)->setDuration(stamp->getDuration());
            timePool.sort();
            break;
        }
    }
    if(it==timePool.end()){
        timePool.push_back(stamp);
        timePool.sort();
    }
    _cond.notify_all();
}



void TimerManger::waitTask(){
    while(1){
        std::shared_ptr<TimeStamp> firstTime;
        std::unique_lock<mutex> locker(_mutex);

        while(firstTime->getTimePoint() <  chrono::system_clock::now()){
            firstTime = timePool.front();
            ThreadPool::instance()->addTask(move(firstTime->getTask()));
            timePool.pop_front();
        }

        firstTime = timePool.front();
        _cond.wait_until(locker,firstTime->getTimePoint());
        while(1){
            firstTime = timePool.front();
            auto diff =  (chrono::system_clock::now() - firstTime->getTimePoint()).count();
            if(diff <= 0.9){
                timePool.pop_front();
                ThreadPool::instance()->addTask(move(firstTime->getTask()));
                std::cout<<"add task"<<firstTime->getFd()<<std::endl;
                break;
            }
            else{
                _cond.wait_until(locker,firstTime->getTimePoint());
            }

        }

    }


}


