#ifndef LOGGER_H
#define LOGGER_H

#include "./LoggerStream.hpp"
#include "../Queue/Queue.hpp"
#include "../ThreadPool/ThreadPool.hpp"
#include "../Task/Task.hpp"
#include<string>
#include<fstream>
#include<sstream>
#include<chrono>
#include <sys/stat.h> 
#include <sys/types.h>

namespace Net{
    using namespace std;
    class Logger{
        public:
            enum LEVEL{
                MESSAGE,WARN
            };
            void setLevel(LEVEL level);
            LoggerStream* steam();
            static Logger* instance();
            ~Logger();
            void flush();
        private:
            LEVEL _level;
            Queue<pair<LEVEL,string>> bufQue;
            LoggerStream* logstream;
            stringstream ss;
            ofstream os;
            Logger();
            void writeThread();
    };
    #define LogDebug(level) Net::Logger::instance()->setLevel(level);\
            *(Net::Logger::instance()->steam())
    //  #define LogDebug(level) Net::Logger::instance()->flush(); \
    //     Net::Logger::instance()->setLevel(level);\
    //         *(Net::Logger::instance()->steam())
}
  
#endif