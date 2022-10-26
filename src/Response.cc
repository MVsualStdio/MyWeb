#include "../include/Response.hpp"
// #include <string.h>
// #include <sys/mman.h>
// #include <fcntl.h>
// #include <unistd.h>

// using namespace Net;
using namespace web;


ResponseCall::Ptr Response::newPtr(ResponseCallBack callback){
    ResponseCall::Ptr res = std::make_shared<Response>(callback);
    return res;
}

std::shared_ptr<Net::HttpResponse> Response::ResRun(Net::HttpRequest request){
    return  callback_(request);
}
