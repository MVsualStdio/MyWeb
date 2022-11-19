#ifndef LOGGER_H
#define LOGGER_H

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
#include "LoggerStream.hpp"
namespace Net{
    using namespace std;

    class Logger{
        public:
            enum LEVEL{
                DEBUG,WARN,MESSAGE
            };
            
            void logInit(string dir,int count);
            static Logger* instance();
            template<typename  T,typename  ... Args> void write_log(LEVEL level, const T& t,const Args&... args);
            ~Logger();

            std::shared_ptr<Queue<std::shared_ptr<Buffer>>> getQue(){
                return bufferPool;
            }
        private:
            template<typename  T,typename  ... Args> void p_write_log(std::stringstream& ss,const T& t,const Args&... args);
            template<typename  T> void p_write_log(std::stringstream& ss,const T& t);
            void mkLogFile();
            string getLogDate();
            void initFileName();
            const static std::unordered_map<LEVEL,string> levelMap;
            int count_;
            string fileName;
            int curCount_;
            string dir_;
            ofstream out_;
            std::shared_ptr<Queue<std::shared_ptr<Buffer>>> bufferPool;
            Logger() = default;
            void writeThread();
        public:
            #define LogWarn  Net::LoggerStream(Net::Logger::instance()->getQue())  << "[Warn] "
            #define LogDebug Net::LoggerStream(Net::Logger::instance()->getQue()) << "[Debug] "
            #define LogMessage Net::LoggerStream(Net::Logger::instance()->getQue()) << "[Message] "
    };




    template <typename  T, typename ... Args>
    void Logger::write_log(LEVEL level, const T &t, const Args &...args){
        std::shared_ptr<Buffer> buf(new Buffer());
        std::stringstream ss; 
        buf->append(levelMap.find(level)->second);
        p_write_log(ss, t, args...);
        buf->append(ss.str());
        bufferPool->push(move(buf));
    }

    template <typename  T, typename ... Args>
    void Logger::p_write_log(std::stringstream& ss, const T &t, const Args &...args){
        ss << t;
        p_write_log(ss, args...);
    }

    template <typename  T>
    void Logger::p_write_log(std::stringstream& ss, const T &t){
        ss << t;
    }


    
}
#endif






