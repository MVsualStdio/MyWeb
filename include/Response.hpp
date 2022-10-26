#ifndef RESPONSE_H
#define RESPONSE_H
#include <unordered_map>
#include "Http/HttpResponse.hpp"
#include "Http/HttpRequest.hpp"
#include <memory>
using namespace std;
#include <functional>




namespace web{

    class ResponseCall{
        public:
            using ResponseCallBack = std::function<std::shared_ptr<Net::HttpResponse> (Net::HttpRequest&)>;
            using Ptr = std::shared_ptr<ResponseCall>;
            virtual std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest request) = 0;
    };

    class Response:public ResponseCall{
        public:
            
        private:
            ResponseCallBack callback_;
        public:
            Response() = default;
            Response(ResponseCallBack callback):callback_(callback){};
            static ResponseCall::Ptr newPtr(ResponseCallBack callback);
            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest request);
    };
}



#endif
