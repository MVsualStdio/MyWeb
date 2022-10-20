#ifndef HTTPCONTEXT_H
#define HTTPCONTEXT_H
#include "HttpRequest.hpp"
#include <algorithm>
#include "../Buffer/Buffer.hpp"
namespace Net{
    class HttpContext{
        public:
            enum HttpRequestParseState{
                kExpectRequestLine,
                kExpectHeaders,
                kExpectBody,
                kGotAll,
            };
        HttpContext(): state_(kExpectRequestLine){}


        bool parseRequest(Buffer* buf);

        bool gotAll() const{ 
            return state_ == kGotAll;
        }

        void reset(){
            state_ = kExpectRequestLine;
            HttpRequest dummy;
            request_.swap(dummy);
        }

        const HttpRequest& request() const{ 
            return request_; 
        }

        const HttpRequestParseState state() const{ 
            return state_; 
        }

        HttpRequest& request(){ 
            return request_; 
        }
        
        private:
            bool processRequestLine(const char* begin, const char* end);
            HttpRequestParseState state_;
            HttpRequest request_;
            int  body_lenth;
    };
}


#endif