#include "HttpResponse.hpp"

void Net::HttpResponse::toBuffer(Buffer* buffer){
    char buf[32];
    snprintf(buf, sizeof buf, "HTTP/1.1 %d ", statusCode);
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
}

