#ifndef LOGGERSTREAM_H
#define LOGGERSTREAM_H

#include<iostream>
#include<string>
namespace Net{
    using namespace std;
    class LoggerStream{
        public:
            LoggerStream(ostream& out);
            void flush(){
                _out.flush();
            }
            ~LoggerStream() = default;
            LoggerStream(const LoggerStream& loggerStream) = delete;
            template<class T>
            const LoggerStream& operator<<(const T& s)const{
                _out<<s;
                return *this;
            }
        protected:
            ostream& _out;
            template<class res, class ...Args>
            res streamProcess(Args ...arg);
    };
}


#endif
