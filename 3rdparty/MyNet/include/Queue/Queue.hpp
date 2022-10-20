#ifndef QUEUE_H
#define QUEUE_H

#include <mutex>
#include <iostream>
#include <queue>
#include <condition_variable>

using namespace std;
namespace Net{
    template<class T>
    
    class Queue{
        private:
            mutex _mutex;
            condition_variable _cond;
            queue<T> _queue;
            int _size;
        public:
            Queue();
            void push(T&& item);
            void push(const T& item);
            T pop();
    };


    template<class T>
    Queue<T>::Queue():_size(0){
    }

    template<class T>
    void Queue<T>::push(T&& item){
        //cout<<"push right"<<endl;
        unique_lock<mutex> locker(_mutex);
        _queue.push(forward<T>(item));
        ++_size;
        _cond.notify_all();
    }

    template<class T>
    void Queue<T>::push(const T& item){
        //cout<<"push left"<<endl;
        unique_lock<mutex> locker(_mutex);
        _queue.push(forward<T>(item));
        ++_size;
        _cond.notify_all();
    }

    template<class T>
    T Queue<T>::pop(){
        unique_lock<mutex> locker(_mutex);
        while(_queue.empty()){
            _cond.wait(locker);
        }
        // cout<<"pop"<<endl;
        T res = _queue.front();
        _queue.pop();
        --_size;
        return res;
    }

}

#endif