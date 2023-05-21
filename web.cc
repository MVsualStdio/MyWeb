
// #include "Http/HttpServer.hpp"
// #include "Socket/Epolloop.hpp"
#include "BlogIndex.hpp"
#include "Login.hpp" 
#include "Index.hpp"
#include "Proxy.hpp"
#include "ProxyServer.hpp"
using namespace web;
using namespace std;




int main(){
    // WebSever web;
    // web.addRoute("/secret/login",Login::newPtr());
    // web.addRoute("/proxy",Proxy::newPtr());
    ProxyServer server;
    // server.addRoute("/proxy",Proxy::newPtr());
    server.start();

}