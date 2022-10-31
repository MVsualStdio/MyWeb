#include "../include/Render.hpp"
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <RenderType.hpp>

using namespace Net;
using namespace web;


int Render::setBuffer(string path){
    path_ = path;
    auto pos = path_.find_last_of('.');
    
    if(pos != path_.length()){
        std::string suffix(path_.begin()+pos,path_.end());
        auto iter = RenderType::SUFFIX_TYPE.find(suffix);
        if(iter != RenderType::SUFFIX_TYPE.end()){
            pathType_ = iter->second;
        }
    }

    if(buffer_){
        UnmapFile();
    }

    string openPath ;
    getPath(openPath);
    //std::cout<<openPath<<std::endl;
    filefd_ = mmapFile(openPath);
    
    return filefd_;
}



void Render::UnmapFile() {
    if(buffer_) {
        munmap(buffer_, pathLen_);
        buffer_ = nullptr;
    }
}

int Render::mmapFile(string file){
    int fd = open(file.c_str(), O_RDONLY);
    if(fd>0){
        pathLen_ = lseek(fd, 0, SEEK_END);
        //  建立映射
        buffer_ = (char *) mmap(NULL, pathLen_, PROT_READ, MAP_PRIVATE, fd, 0);
    }
    else{
        fd = open("./static/html/404.html", O_RDONLY);
        pathLen_ = lseek(fd, 0, SEEK_END);
        //  建立映射
        buffer_ = (char *) mmap(NULL, pathLen_, PROT_READ, MAP_PRIVATE, fd, 0);
    }

    return fd;
}


void Render::getPath(string& path){
    // if(pathType_ == "text/html"){
    //     path = "./static/html/"+path_;
    // }
    
    // else if(pathType_ == "text/css"){
    //     path = "./static/css/"+path_;
    // }

    // else if(pathType_ == "text/javascript"){
    //     path = "./static/js/"+path_;
    // }
    // else{
    path = "./static/" + path_;
    //}
}

void Render::setResp(std::shared_ptr<Net::HttpResponse> resp,HttpResponse::HttpStatusCode code){
        
    if(filefd_>0){
        resp->setStatusCode(code);
        switch (code){
            case HttpResponse::K200Ok :
                resp->setStatusMessage("OK");
                break;
            case HttpResponse::K302Found :
                resp->setStatusMessage("Found");
                break;
            default:
                break;
        }
        resp->setContentType(pathType_);
        if(pathLen_>0){
            resp->setBody(std::string(buffer_,buffer_ + pathLen_));
        }
    }
    else{
        resp->setStatusCode(HttpResponse::K404NotFound);
        resp->setStatusMessage("Bad Request");
        resp->setContentType("text/html");
        resp->setBody(buffer_);
    }
}


std::shared_ptr<Net::HttpResponse> Render::SendContent(string content,RenderType::ResponseType type){
    std::shared_ptr<Net::HttpResponse> resp(new Net::HttpResponse(true));
    resp->setStatusCode(HttpResponse::K200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType(RenderType::ResponseTypeMap.find(type)->second);
    resp->setBody(content);
    return resp;
}

std::shared_ptr<Net::HttpResponse> Render::sendRedirect(string path){
    std::shared_ptr<Net::HttpResponse> resp(new Net::HttpResponse(true));
    filefd_ = setBuffer(path);
    auto pos = path_.find('.');
    resp->addHeader("Location",string(path_.begin(),path_.begin()+pos));
    resp->setBody(buffer_);
    setResp(resp,HttpResponse::K302Found);
    close(filefd_);
    UnmapFile();
    return resp;
}

std::shared_ptr<Net::HttpResponse> Render::SendHtml(string path){
    std::shared_ptr<Net::HttpResponse> resp(new Net::HttpResponse(true));
    filefd_ = setBuffer(path);
    setResp(resp,HttpResponse::K200Ok);
    close(filefd_);

    UnmapFile();
    return resp;
}