#include "Buffer.hpp"
#include "../Socket/Connectserver.hpp"

using namespace Net;
const char Buffer::kCRLF[] = "\r\n";

void Buffer::ensureInsert(int length){

    if (getFreeSize() >= length) {
        return;
    }
    int min_cap_need = capacity + length;
    if(min_cap_need > maxCapacity){
        throw std::runtime_error("out of capacity");
    }
    int newcap = capacity + length;
    int doublecap = capacity*2;
    if(min_cap_need > doublecap){
        newcap = min_cap_need;
    }
    else{
        if(capacity < 1024){
            newcap = doublecap <= maxCapacity ? doublecap : maxCapacity;
        }
        else{
            while(newcap < min_cap_need){
                newcap += newcap/4;
                if(newcap > maxCapacity){
                    newcap = maxCapacity;
                    break;
                }
            }
        }
    }
    resize(newcap);
}

void Buffer::resize(int newcap){
    int unread_size = getUnreadSize();
    if (newcap == capacity) {
        return;
    }


    char* temp = new char[newcap+1];
    for (int i = 0; i < unread_size; i++) {
        int cur_index = (readPos + i) % capacity;
        memcpy(temp + i, buffer + cur_index, 1);
    }
    delete []buffer;
    buffer = temp;
    capacity = newcap;
    dataSize = capacity+1;
    readPos = 0;
    writePos = unread_size;
}

int Buffer::getUnreadSize(){
    return writePos - readPos;
}

int Buffer::getFreeSize(){
    return capacity - writePos;
}

int Buffer::read(char* data,int length){
    if(length > getUnreadSize()){
        return -1;
    }
    int curIndex = readPos;
    for (int i = 0; i < length; i++) {
        curIndex = (readPos + i) % dataSize;
        memcpy(data + i,  buffer + curIndex, 1);
    }
    readPos = (curIndex + 1) % dataSize;
    return length;
}


int Buffer::writeBuffer(const char* data,int length){
    if (length <= 0) {
        return 0;
    }
    ensureInsert(length);

    int curIndex = writePos;
    for(int i=0;i<length;++i){
        curIndex = (writePos + i) % dataSize;
        memcpy(buffer + curIndex,data + i, 1);
    }
    
    writePos = (curIndex+1)%dataSize;

    // std::cout<<"length"<<length<<std::endl;
    // std::cout<<"size:  "<<getUnreadSize()<<std::endl;
    // std::cout<<"peek"<<peek()<<std::endl;
    // std::cout<<"data"<<data<<"   "<<std::endl;
    // std::cout<<"buffer"<<buffer<<"   "<<std::endl;
    // std::cout<<"readPos"<<readPos<<std::endl;
    // std::cout<<"dataSize"<<dataSize<<std::endl;
    // std::cout<<"getFreeSize"<<getFreeSize()<<std::endl;
    // std::cout<<"writePos"<<writePos<<std::endl;
    return length;
}

int Buffer::writeConnect(Connectserver* con){
    int fd = con->getFd();
    int total_sent_num = 0;
    while (getUnreadSize() > 0) {
        int cur_send_len = writePos - readPos;
        if (readPos > writePos) {
            cur_send_len = capacity - readPos;
        }
        size_t writeNum = ::write(fd, buffer + readPos, cur_send_len);
        if (writeNum == 0) {
            if (errno == EINTR) {
                continue;
            } else {
                // 缓冲区满了，或者写入报错，直接退出
                break;
            }
        }
        readPos = (readPos + writeNum) % dataSize;
        total_sent_num += writeNum;
  }
  return total_sent_num;
}

int Buffer::writeConnect(Connectserver* con,std::string msg){
    int fd = con->getFd();
    size_t writeNum = ::write(fd, msg.c_str(), msg.length());
    return writeNum;
}

int Buffer::readConnect(Connectserver* con){
    int socketfd = con->getFd();
    if(socketfd < 0) {
        LogDebug(Net::Logger::WARN) << "socket id minus error, errno: "<< errno;
        return -1;
    }
    char line[MAX_LINE];
    bzero(line, MAX_LINE);
    char buff[65535];
    struct iovec iov[2];
    iov[0].iov_base = line;
    iov[0].iov_len = sizeof(line);
    iov[1].iov_base = buff;
    iov[1].iov_len = sizeof(buff);

    ssize_t read_length = ::read(socketfd, line, MAX_LINE);

    if(read_length < 0) {
        if(errno == ECONNRESET) {
            LogDebug(Net::Logger::WARN) << "ECONNRESET error, closed: " << socketfd;
            return -1;
        } 
    } 

    writeBuffer(line,read_length);
    if(read_length > MAX_LINE){
        writeBuffer(buff,read_length-MAX_LINE);
    }
    return read_length;
}


void Buffer::clean(){
    readPos = 0;
    writePos = 0;
}

void Buffer::append(std::string data){
    writeBuffer(data.c_str(),data.size());
}

const char* Buffer::findCRLF() const{
    const char* crlf = std::search(buffer+readPos, buffer+writePos, kCRLF, kCRLF+2);
    return crlf == buffer+writePos ? NULL : crlf;
}

void Buffer::retrieve(int len){
    if(len > getUnreadSize()){
        std::cout<<"retrieve len is error"<<std::endl;
        return;
    }
    int curIndex = readPos;
    readPos = (curIndex+len)%dataSize;
}

void Buffer::retrieveUntil(const char* newRead){
    int len = newRead - peek();
    retrieve(len);
}