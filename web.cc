
// #include "Http/HttpServer.hpp"
// #include "Socket/Epolloop.hpp"

#include "WebServer.hpp"
#include "Login.hpp" 
using namespace web;
using namespace std;




int main(){
    GetSql->addQuery("web","web_user","user_name","wang");
    WebSever web;
    web.addSouce("image");
    //web.addRoute("/",Login::newPtr());
    web.addRoute("/",Response::newPtr([](HttpRequest& resp){return GetRender->SendHtml("index.html");}));
    web.addRoute("/welcome",Response::newPtr([](HttpRequest& resp){return  GetRender->SendHtml("welcome.html");}));
    web.addRoute("/hello",Response::newPtr([](HttpRequest& resp){return  GetRender->SendHtml("hello.md");}));
    web.start();

}