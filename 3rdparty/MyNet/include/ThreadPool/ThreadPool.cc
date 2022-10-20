
#include "ThreadPool.hpp"

using namespace Net;

ThreadPool* ThreadPool::threadpool=nullptr;

ThreadPool* ThreadPool::instance(){

    if(threadpool == nullptr){
        threadpool = new ThreadPool();
    }
    return threadpool;
    
}

void ThreadPool::createThread(int num){
    // unique_lock<mutex> locker(_mutex);
    for(int i=0;i<num;++i){
        poolQueue.emplace_back(
            ([this](){
                run();
            }));
    }
}

ThreadPool::ThreadPool():threadNum(10),_isrunning(1){
    createThread(threadNum);
    //mangerThread = static_cast<unique_ptr<thread>>(new thread([this](){mangerun();}));
}

ThreadPool::~ThreadPool(){
    {
        unique_lock<std::mutex> lock(_mutex);
        _isrunning = 0;
    }
    _cond.notify_all();
    for(int i=0;i<poolQueue.size();++i){
        if(poolQueue[i].joinable()){
            poolQueue[i].join();
        }    
    }
    //mangerThread->join();
    if(threadpool){
        delete threadpool;
    }

}

void ThreadPool::addTask(shared_ptr<WorkItem>&& Task){
    unique_lock<mutex> locker(_mutex);
    workQueue.push(move(Task));
    //cout<<"add task task num is"<<workQueue.size()<<endl;
    _cond.notify_all();
}

void ThreadPool::run(){
    while(true){
        {
            unique_lock<mutex> locker(_mutex);
            if(!workQueue.empty()){
                auto Task = move(workQueue.front());
                workQueue.pop();
                locker.unlock();
                Task->run();
                locker.lock();
            }
            else if(!_isrunning){
                break;

            }
            else{
                _cond.wait(locker);
            }
            // if(workQueue.empty() && _isrunning){
            //     _cond.wait(locker);
            //     // if(exitNum > 0){
            //     //     --exitNum;
            //     //     return ;
            //     // }
            // }

        }
        
    }
}

// void ThreadPool::mangerun(){
//     while(_isrunning){
//         unsigned int tasknum=0;
//         unsigned int threadnum=0;
//         {
//             unique_lock<mutex> lock(_mutex);
//             tasknum = workQueue.size();
//             threadnum = poolQueue.size();
//         }
//         //cout<<"current thread num is"<<threadnum<<endl;
//         if(tasknum > threadnum*2){
//             createThread(2);
//         }

//         {
//             unique_lock<mutex> lock(_mutex);
//             if(tasknum <  threadnum && threadnum > 5){
//                 exitNum = 1 ;
//                 _cond.notify_all();
//             }
//         }
//         cout<<"current task num is"<<tasknum<<endl;
//         cout<<"current thread num is"<<threadnum<<endl;
//         sleep(1);
//     }
    
// }