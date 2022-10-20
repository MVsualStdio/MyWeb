#ifndef RENDER_H
#define RENDER_H
#include <unordered_map>
#include "Http/HttpResponse.hpp"
#include <memory>
using namespace std;


namespace web{
    class Render{
        private:
            string path_;
            string pathType_;
            int filefd_;
            char* buffer_;
            size_t pathLen_;
            
        private:
            void UnmapFile();
            int mmapFile(string file);
            void getPath(string& path);
            void setResp(std::shared_ptr<Net::HttpResponse>,Net::HttpResponse::HttpStatusCode coderesp);
            int setBuffer(string path);
        public:
            Render() = default;
            std::shared_ptr<Net::HttpResponse> SendHtml(string path);
            std::shared_ptr<Net::HttpResponse> SendContent(string content);
            std::shared_ptr<Net::HttpResponse> sendRedirect(string path);
    };
}



#endif
