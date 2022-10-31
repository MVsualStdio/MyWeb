#ifndef ROUTE_H
#define ROUTE_H

#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include "Response.hpp"
#include "Http/HttpResponse.hpp"
#include "Render.hpp"
#include "RenderPool.hpp"
using namespace std;

namespace web{
    class Route{
        public:
        private:
            //Render render_;
            std::string sourcePath;
            unordered_map<string,ResponseCall::Ptr> route_;
            void addStaticSource();
            bool getAllFiles(const std::string& dir_in, std::vector<std::string>& files,std::string root);
        public:
            Route();
            void addSourceDir(std::string dir);
            void addRoute(string oneRoute,ResponseCall::Ptr res);
            bool isExistRoute(string oneRoute);
            ResponseCall::Ptr getResponse(string path);
    };
}


#endif