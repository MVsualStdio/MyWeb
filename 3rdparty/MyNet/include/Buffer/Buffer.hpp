#ifndef BUFFER_H
#define BUFFER_H

#include<atomic>
#include<vector>
#include<string>
#include <string.h>
#include<exception>
#include<stdexcept>
#include <algorithm>
#include <iostream>


namespace Net
{
    class Connectserver;
    class Buffer{
        private:
            int readPos;
            int writePos;
            char* buffer;
            int capacity;
            int maxCapacity;
            int dataSize;
            static const char kCRLF[];
        public:
            Buffer(int capacit=8):readPos(0),writePos(0),\
                                capacity(capacit),dataSize(capacity+1){
                buffer = new char[dataSize];
            };
            ~Buffer(){
                delete buffer;
            }
            const char* peek() const{ return buffer+readPos;}
            const char* end() const{ return buffer+writePos;}
            void retrieve(int len);
            void retrieveUntil(const char* newRead);
            int getUnreadSize();
            int getFreeSize();
            int read(char* data,int length);
            void append(std::string s);
            int writeBuffer(const char *data,int length);
            int writeConnect(Connectserver* con);
            int writeConnect(Connectserver* con,std::string msg);
            int readConnect(Connectserver* con);
            void clean();
            const char* findCRLF() const;
            // int maxLength();
        private:
            void ensureInsert(int length);
            void resize(int newcap);
    };
} // namespace Net



#endif