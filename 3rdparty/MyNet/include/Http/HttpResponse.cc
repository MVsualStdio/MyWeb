#include "HttpResponse.hpp"
#include "HttpContext.hpp"

void Net::HttpResponse::toBuffer(std::list<std::shared_ptr<Buffer>>& buffers,int listSize){
    char buf[32];
    
    snprintf(buf, sizeof buf, "HTTP/1.1 %d ", statusCode);
    std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>();
    
    buffer->append(buf);
    buffer->append(statusMessage);
    buffer->append("\r\n");
    if (closeConnection_){
        buffer->append("Connection: close\r\n");
    }
    else {
        snprintf(buf, sizeof buf, "Content-Length: %zd\r\n", body.size());
        buffer->append(buf);
        buffer->append("Connection: Keep-Alive\r\n");
    }
    for (auto he : header)
    {
        buffer->append(he.first);
        buffer->append(": ");
        buffer->append(he.second);
        buffer->append("\r\n");
    }
    buffer->append("\r\n");
    buffer->append(body);
    buffers.push_back(buffer);

    // for(int i=0;i<body.size()/listSize+1;++i){
    //     std::shared_ptr<Buffer> body_buffer = std::make_shared<Buffer>();
    //     if((i+1)*listSize > body.size()){
    //          body_buffer->append(std::string(body.begin()+i*listSize,body.begin()+body.size()));
    //     }
    //     else{
    //         std::string snewstring(body.begin()+i*listSize,body.begin()+(i+1)*listSize);
    //         body_buffer->append(std::string(body.begin()+i*listSize,body.begin()+(i+1)*listSize));
    //     }
    //     buffers.push_back(body_buffer);
    // }

}


