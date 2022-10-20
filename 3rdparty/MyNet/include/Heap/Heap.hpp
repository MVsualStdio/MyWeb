
#ifndef HEAP_H
#define HEAP_H

#include<vector>
#include<mutex>
#include<condition_variable>
#include<iostream>
namespace Net{
    using namespace std;
    template<class T>
    class Heap{
        private:
            vector<T> _heapQueue;
            mutex _mutex;
            condition_variable _cond;
            void  heapswap(T& q1,T& q2);
        public:
            Heap(){};
            ~Heap(){};
            void push(T& item);
            T pop();
            unsigned int size();
    };
    


    template<class T>
    void Heap<T>::push(T& item){
        unique_lock<mutex> locker(_mutex);
        _heapQueue.push_back(item);
        int size = _heapQueue.size();
        int k = size-1;
        // if(size == 0){
            
        //     return;
        // }
        while(k > 0 && _heapQueue[k] < _heapQueue[k/2]){
            this->heapswap(_heapQueue[k],_heapQueue[k/2]);
            k = k/2;
        }

        // for(int i=0;i<size;++i){
        //     cout<<"sort:"<<_heapQueue[i]<<"    ";
        // }
        // cout<<endl;

        _cond.notify_all();
    }
    
    template<class T>
    T Heap<T>::pop(){
        unique_lock<mutex> locker(_mutex);
        while(_heapQueue.empty()){
            _cond.wait(locker);
        }
        int size = _heapQueue.size();
        T firstItem = _heapQueue.front();
        _heapQueue[0] = _heapQueue[size-1];
        _heapQueue.pop_back();
        int k = 0;
        while(k*2 < size){
            int j = k*2+1;
            if(j<size-1 && _heapQueue[j+1] < _heapQueue[j]) ++j;
            if(_heapQueue[k] < _heapQueue[j]) break;
            this->heapswap(_heapQueue[k],_heapQueue[j]);
            k = j;
        }
        return firstItem;
    }

    template<class T>
    unsigned int Heap<T>::size(){
        unique_lock<mutex> locker(_mutex);
        return _heapQueue.size();
    }


    template<class T>
    void Heap<T>::heapswap(T& h1,T& h2){
        T temp = h1;
        h1 = h2;
        h2 = temp;
    }
}



#endif