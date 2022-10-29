#ifndef RENDERTYPE_H
#define RENDERTYPE_H
#include <unordered_map>
#include <string>
#include "Http/HttpResponse.hpp"
namespace 
    web{
        namespace RenderType{
            
            enum ResponseType{
                json
            };

            const std::map<ResponseType,std::string> ResponseTypeMap{
                {ResponseType::json,"application/json"}
            };

            const std::unordered_map<std::string, std::string> SUFFIX_TYPE = {
                { ".html",  "text/html" },
                { ".xml",   "text/xml" },
                { ".xhtml", "application/xhtml+xml" },
                { ".txt",   "text/plain" },
                { ".rtf",   "application/rtf" },
                { ".pdf",   "application/pdf" },
                { ".word",  "application/nsword" },
                { ".png",   "image/png" },
                { ".gif",   "image/gif" },
                { ".jpg",   "image/jpeg" },
                { ".jpeg",  "image/jpeg" },
                { ".au",    "audio/basic" },
                { ".mpeg",  "video/mpeg" },
                { ".mpg",   "video/mpeg" },
                { ".avi",   "video/x-msvideo" },
                { ".gz",    "application/x-gzip" },
                { ".tar",   "application/x-tar" },
                { ".css",   "text/css"},
                { ".js",    "text/javascript"},
            };


            const std::map<Net::HttpResponse::HttpStatusCode, std::string> ERROR_ACCESS_PATH = {
                {Net::HttpResponse::K404NotFound,"./static/html/404.html"}
            };
        }
    }

#endif