
// #include "Http/HttpServer.hpp"
// #include "Socket/Epolloop.hpp"
#include "BlogIndex.hpp"
#include "Login.hpp" 
#include "Index.hpp"
using namespace web;
using namespace std;




int main(){
    WebSever web;
    web.addRoute("/secret/login",Login::newPtr());
    web.start();

}