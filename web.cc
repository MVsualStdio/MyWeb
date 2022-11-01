// #include "Http/HttpServer.hpp"
// #include "Socket/Epolloop.hpp"
#include "BlogIndex.hpp"
#include "Index.hpp"
using namespace web;
using namespace std;




int main(){
    WebSever web;
    //web.addSouce("image");
    //web.addRoute("/",Login::newPtr());
    // web.addRoute("/",Index::newPtr());
    // web.addRoute("/archives/",Archives::newPtr());
    //web.addRoute("/blogIndex",BlogIndex::newPtr());
    // web.addRoute("/welcome",Response::newPtr([](HttpRequest& resp){return  GetRender->SendHtml("welcome.html");}));
    // web.addRoute("/hello",Response::newPtr([](HttpRequest& resp){return  GetRender->SendHtml("hello.md");}));
    web.start();

}