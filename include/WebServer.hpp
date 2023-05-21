#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Response.hpp"
#include "Http/HttpServer.hpp"
#include "Socket/Epolloop.hpp"
#include "Route.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <sys/mman.h>
#include <fcntl.h>
#include <regex>
#include "RenderPool.hpp"
#include "WebConfig.hpp"
using namespace std;
using namespace Net;


namespace web{
    class WebSever{
        public:
        private:
            Route route_;
           
        public:
            WebSever();
               
            void start();
              
            void addRoute(string path, ResponseCall::Ptr res);
            
             std::shared_ptr<Net::HttpResponse> onRequest(const HttpRequest& req);
            // void addSouce(string dir);
             
    };
}

#endif