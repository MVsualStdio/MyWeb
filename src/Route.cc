#include "../include/Route.hpp"
#include "../include/Render.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
using namespace web;


bool Route::getAllFiles(const std::string& dir_in, std::vector<std::string>& files) {
    if (dir_in.empty()) {
        
        return false;
    }
    struct stat s;
    stat(dir_in.c_str(), &s);
    if (!S_ISDIR(s.st_mode)) {
        return false;
    }
    DIR* open_dir = opendir(dir_in.c_str());
    if (NULL == open_dir) {
        std::exit(EXIT_FAILURE);
    }
    dirent* p = nullptr;
    while( (p = readdir(open_dir)) != nullptr) {
        struct stat st;
        if (p->d_name[0] != '.') {
            std::string name =  std::string(p->d_name);
            stat(name.c_str(), &st);
            files.push_back(name);
        }
    }
    closedir(open_dir);
    return true;
}


Route::Route(){
   addStaticSource("css");
   addStaticSource("js");
}

void Route::addStaticSource(string type){
    std::vector<std::string> files;
    if(getAllFiles("./static/"+type,files)){
        for(auto& file:files){
            addRoute("/"+file,Response::newPtr([this,file](Net::HttpRequest resp){return render_.SendHtml(file);}));
        }
    }
}

void Route::addRoute(string oneRoute,ResponseCall::Ptr res){
    route_[oneRoute] = res;                      
}

bool Route::isExistRoute(string oneRoute){
    auto iter = route_.find(oneRoute);
    return !(iter == route_.end());
}

ResponseCall::Ptr Route::getResponse(string path){
    return  route_[path];
}