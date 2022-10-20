#ifndef THREADPOOL
#define THREADPOOL

#include<thread>
#include<queue>
#include<memory>
#include<utility>
#include<mutex>
#include<unistd.h>
#include<condition_variable>
#include "../Task/Task.hpp"
#include "../Task/WorkItem.hpp"

namespace Net{
    using namespace std;
    class ThreadPool{
        public:
            static ThreadPool* instance();
            void addTask(shared_ptr<WorkItem>&& Task);
            ~ThreadPool();

        private:
            void run();
            void mangerun();
            void createThread(int num);
            ThreadPool();
            mutex _mutex;
            condition_variable _cond;
            
            int threadNum;
            // int busyNum;
            // int exitNum;
            bool _isrunning;
            // unique_ptr<thread> mangerThread;
            vector<thread> poolQueue;
            queue<shared_ptr<WorkItem>> workQueue;
            static ThreadPool* threadpool;
    };
}

#endif