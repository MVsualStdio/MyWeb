// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is a public header file, it must only include public header files.

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <iostream>
#include <map>
#include <assert.h>
#include <stdio.h>
#include <unordered_map>

namespace Net{
    using namespace std;
    class HttpRequest {
    public:
    enum Method{
        kInvalid, kGet, kPost, kHead, kPut, kDelete
    };
    enum Version{
        kUnknown, kHttp10, kHttp11
    };

    HttpRequest()
        : method_(kInvalid),
        version_(kUnknown){}

    void setVersion(Version v){
        version_ = v;
    }

    Version getVersion() const
        { return version_; }

    bool setMethod(const char* start, const char* end){
        assert(method_ == kInvalid);
        std::string m(start, end);
        if (m == "GET"){
            method_ = kGet;
        }
        else if (m == "POST"){
            method_ = kPost;
        }
        else if (m == "HEAD"){
            method_ = kHead;
        }
        else if (m == "PUT"){
            method_ = kPut;
        }
        else if (m == "DELETE"){
            method_ = kDelete;
        }
        else{
            method_ = kInvalid;
        }
        return method_ != kInvalid;
    }

    Method method() const
    { return method_; }

    const char* methodString() const{
        const char* result = "UNKNOWN";
        switch(method_)
        {
        case kGet:
            result = "GET";
            break;
        case kPost:
            result = "POST";
            break;
        case kHead:
            result = "HEAD";
            break;
        case kPut:
            result = "PUT";
            break;
        case kDelete:
            result = "DELETE";
            break;
        default:
            break;
        }
        return result;
    }

    void setPath(const char* start, const char* end){
        path_.assign(start, end);
    }

    const std::string& path() const{ 
        return path_; 
    }

    void setQuery(const char* start, const char* end){
        query_.assign(start, end);
    }

    const std::string& query() const{ 
        return query_; 
    }

    void setPostBody(const char* start,const char* end){
        postbody_.assign(start,end);
    }

    unordered_map<string,string> postBody() const{ 
        // std::cout<<postbody_<<std::endl;
        unordered_map<string,string> res;
        int first = 0;
        int pos=0;
        while(pos<postbody_.size()){
            int key = postbody_.find('=',pos);
            int value = postbody_.find('&',key);
            if(value == -1){
                value = postbody_.size();
            }
            string reskey(pos+postbody_.begin(),key+postbody_.begin());
            string resvalue(key+postbody_.begin()+1,value+postbody_.begin());
            res[reskey] = resvalue;
            pos = value+1;
        }
        return res; 
    }

    void addHeader(const char* start, const char* colon, const char* end){
        string field(start, colon);
        ++colon;
        while (colon < end && isspace(*colon)){
            ++colon;
        }
        string value(colon, end);
        while (!value.empty() && isspace(value[value.size()-1])){
            value.resize(value.size()-1);
        }
        headers_[field] = value;
    }

    std::string getHeader(const string& field) const{
        string result;
        std::map<string, string>::const_iterator it = headers_.find(field);
        if (it != headers_.end())
        {
        result = it->second;
        }
        return result;
    }

    const std::map<string, string>& headers() const
    { return headers_; }

    void swap(HttpRequest& that){
        std::swap(method_, that.method_);
        std::swap(version_, that.version_);
        path_.swap(that.path_);
        query_.swap(that.query_);
        headers_.swap(that.headers_);
    }

    private:
        Method method_;
        Version version_;
        std::string path_;
        std::string query_;
        std::map<std::string, std::string> headers_;
        std::string postbody_;
    };

}  // namespace net


#endif