#ifndef TASK_H
#define TASK_H

#include<utility>
#include <functional>
#include<iostream>
#include<thread>
#include "WorkItem.hpp"
namespace Net{

    using namespace std;
    
    typedef std::function<void()> taskFun;
    class Task : public WorkItem{
        private:
            taskFun _task;
        public:

            template<class T,class  ...Args>
            Task(T&& task,Args&& ...args){
                 _task = bind(std::forward<T>(task), std::forward<Args>(args)...);
            }

            void run(){
                if(_task == nullptr){
                    cout<<"ERROR"<<endl;
                    return ;
                }
                _task();
            }
    };
}

#endif