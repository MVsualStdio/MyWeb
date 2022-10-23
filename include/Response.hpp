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
        virtual std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest request) = 0;

    };

    class Response:public ResponseCall{
        public:
            using ResponseCallBack = std::function<std::shared_ptr<Net::HttpResponse> (Net::HttpRequest&)>;
        private:
            ResponseCallBack callback_;
        public:
            Response() = default;
            Response(ResponseCallBack callback):callback_(callback){};
            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest request){
                return  callback_(request);
            }
    };
}



#endif
