#ifndef ROUTE_H
#define ROUTE_H

#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include "Response.hpp"
#include "Http/HttpResponse.hpp"
#include "Render.hpp"
using namespace std;

namespace web{
    class Route{
        public:
        private:
            Render render_;
            unordered_map<string,Response> route_;
            void addStaticSource(string dir);
            static bool getAllFiles(const std::string& dir_in, std::vector<std::string>& files);
        public:
            Route();
            void addRoute(string oneRoute,Response res);
            bool isExistRoute(string oneRoute);
            Response getResponse(string path);
    };
}


#endif