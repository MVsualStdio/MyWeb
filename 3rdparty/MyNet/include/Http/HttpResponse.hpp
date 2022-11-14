#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H
#include <map>
#include <string>
#include <memory>
#include <list>
#include "../Buffer/Buffer.hpp"
namespace Net{
    class HttpResponse{
        public:
            enum HttpStatusCode{
                KUnknow,
                K200Ok = 200,
                K404NotFound = 404,
                K302Found = 302
            };
        private:
            bool closeConnection_;
            std::map<std::string,std::string> header;
            std::string body;
            std::string statusMessage;
            HttpStatusCode statusCode;
        public:
            explicit HttpResponse(bool close):closeConnection_(close),statusCode(HttpStatusCode::KUnknow){};
            void addHeader(const std::string& key,const std::string& value)
                {header[key]=value;}
            void setBody(const std::string& _body)
                {body=_body;}
            void toBuffer(std::list<std::shared_ptr<Buffer>>& buffer,int listSize);
            void setContentType(const std::string& type)
                {addHeader("Content-Type", type);}
            void setStatusCode(HttpStatusCode code){statusCode = code;}
            void setStatusMessage(const std::string& message){statusMessage = message;};
            void setCloseConnect(bool on){closeConnection_ = on;}
            bool closeConnection(){return closeConnection_;}
    };
}

#endif