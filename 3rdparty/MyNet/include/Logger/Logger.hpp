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
#include <map>
namespace Net{
    using namespace std;
    class Logger{
        public:
            enum LEVEL{
                MESSAGE,WARN
            };
            
            void logInit(string dir,int count);
            static Logger* instance();
            template<class T,class ... Args>
            void write_log(LEVEL level, const T& t,const Args&... args);
            ~Logger();

        private:
            template<class T,class ... Args> void p_write_log(std::shared_ptr<Buffer> s,const T& t,const Args&... args);
            template<class T> void p_write_log(std::shared_ptr<Buffer> s,const T& t);
            const static std::map<LEVEL,string> levelMap;
            int count_;
            string dir_;
            ofstream out_;
            std::mutex mutex_;
            Queue<std::shared_ptr<Buffer>> bufferPool;
            Logger();
            void writeThread();
    };
    #define LogDebug
}
  
#endif


