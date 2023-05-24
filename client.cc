#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
// #include "Http/HttpResponse.hpp"
// #include "RenderPool.hpp"
// #include "Render.hpp"
// #include "Route.hpp"
// #include "Http/HttpRequest.hpp"
// #include "RenderPool.hpp"
// #include "MysqlPool.hpp"
// #include <nlohmann/json.hpp>

using namespace std;


int main(){
    //创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(6868);  //端口

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    cout<<"connect"<<endl;
    // Net::HttpResponse res(true);
    // list<std::shared_ptr<Net::Buffer>> buffer;

    // // res = GetRender->SendContent("123",RenderType::ResponseType::text);

    // res.toBuffer(buffer,10);
    // for(auto& buf : buffer ){
    //     // buf->writeConnect(pCon);
    //     cout << buf->peek() <<endl;
    // }


    //读取服务器传回的数据
    char buffer[65536] = "GET /proxy HTTP/1.1\r\n"
            "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\r\n"
            "Accept-Encoding: gzip, deflate\r\n"
            "Accept-Language: zh-CN,zh;q=0.9\r\n"
            "Cache-Control: max-age=0\r\n"
            "Host: 81.70.1.235:6869\r\n"
            "Upgrade-Insecure-Requests: 1\r\n"
            "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36\r\n\r\n";
    write(sock, buffer, sizeof(buffer)-1);
    read(sock, buffer, sizeof(buffer)-1);
    printf("Message form server: %s\n", buffer);
   
    //关闭套接字
    close(sock);

    return 0;

}