#ifndef LOGGERSTREAM_H
#define LOGGERSTREAM_H

#include "../Queue/Queue.hpp"
#include "../ThreadPool/ThreadPool.hpp"
#include "../Task/Task.hpp"
#include "../Buffer/Buffer.hpp"
#include<string>
#include<fstream>
#include<sstream>
#include<chrono>
#include <sys/stat.h> 
#include <sys/types.h>
#include <unordered_map>
namespace Net{
    class LoggerStream : public std::stringstream{
        private:
            //stringstream ss;
            std::shared_ptr<Queue<std::shared_ptr<Buffer>>> bufferPool;
        public:
            void setQueue();
            LoggerStream& stream(){
                return *this;
            }
            LoggerStream(std::shared_ptr<Queue<std::shared_ptr<Buffer>>> que):bufferPool(que){
                this->clear();
            }
            void Fflush(){
                this->flush();
                this->clear();
            }
            ~LoggerStream(){
                std::shared_ptr<Buffer> buf(new Buffer());
                buf->append(this->str());
                bufferPool->push(std::move(buf));
                Fflush();
            }
    };
}

#endif