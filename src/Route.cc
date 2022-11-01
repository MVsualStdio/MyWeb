#include "../include/Route.hpp"
#include "../include/Render.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Config.hpp"
#include <unistd.h>
using namespace web;


bool Route::getAllFiles(const std::string& dir_in, std::vector<std::string>& files,std::string root) {
    std::string curDir = sourcePath + root;
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
            //std::cout<<"con: "<<curDir+name<<std::endl;

            stat((curDir+name).c_str(), &st);
            if (S_ISDIR(st.st_mode)) {
                //std::cout<<"dir:"<<(sourcePath+name)<<std::endl;
                getAllFiles(curDir+name+"/", files,root+name+"/");
            }
            else{
                // std::cout<<"root name: "<<root+name<<std::endl;
                files.push_back(root+name);
            }
            
        }
    }
    closedir(open_dir);
    return true;
}


Route::Route(){

    sourcePath = Config::SourceDir;
    
    std::cout<<sourcePath<<std::endl;
//    addStaticSource("css");
//    addStaticSource("js");
    addStaticSource();

}

void Route::addStaticSource(){
    std::vector<std::string> files;
    if(getAllFiles(sourcePath,files,"")){
        for(auto& file:files){
            std::string loc(file);
            int pos = 0;
            if(loc.substr(loc.size()-10,loc.size()) == "index.html"){
                addRoute("/"+loc.substr(0,loc.size()-10),Response::newPtr([this,loc,pos](Net::HttpRequest resp){return GetRender->SendHtml(loc);}));
                //std::cout<<loc.substr(0,loc.size()-10)<<std::endl;
            }
            else{
                addRoute("/"+loc,Response::newPtr([this,loc](Net::HttpRequest resp){return GetRender->SendHtml(loc);}));
                //std::cout<<loc<<std::endl;
            }
            // std::cout<<"loc:"<<loc<<std::endl;
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