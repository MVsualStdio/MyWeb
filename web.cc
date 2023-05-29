
// #include "Http/HttpServer.hpp"
// #include "Socket/Epolloop.hpp"
#include "BlogIndex.hpp"
#include "Login.hpp" 
#include "Index.hpp"
#include "Proxy.hpp"
#include "ProxyServer.hpp"
using namespace web;
using namespace std;

void webStart(){
    WebSever web;
    web.addRoute("/secret/login",Login::newPtr());
    // shared_ptr<Proxy> Ptr(new Proxy());
    // Ptr->ProxyInitHost("127.0.0.1",6869);
    // web.addRoute("/proxy",Ptr);
    web.start();
}

void proxyStart(){
    ProxyServer server;
    
    server.start();
}

int main(){
    webStart();
}