#include "Response.hpp"
// #include "Http/HttpServer.hpp"
// #include "Socket/Epolloop.hpp"
#include "Route.hpp"
#include "Render.hpp"
#include "WebServer.hpp"
#include "MysqlPool.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <sys/mman.h>
#include <fcntl.h>
#include <regex>
#include <RenderPool.hpp>
using namespace web;
using namespace std;
using namespace Net;


// void onRequest(const HttpRequest& req, HttpResponse* resp){
//     std::cout << "Headers " << req.methodString() << " " << req.path() << std::endl;
//     string path = req.path();
//     // cout<<req.postBody()<<endl;
//     if(Route::isExistRoute(path)){
//         Response s =  Route::getResponse(path);
//         s.ResRun(resp);
//     }
// }




std::shared_ptr<HttpResponse> login(HttpRequest& req){
    if(req.method() == HttpRequest::Method::kPost){
        unordered_map<string,string> parsebody =  req.postBody();
        auto res = GetSql->getQueryResult("web","web_user","user_name",parsebody["u"]).fetchOne();
        //std::cout<<res[2]<<std::endl;
        if(!res[2].isNull()  && res[2].get<string>() == parsebody["p"]){
            return GetRender->sendRedirect("/welcome.html");
        }
    }
    return GetRender->SendHtml("/login.html");
}

int main(){
    GetSql->addQuery("web","web_user","user_name","wang");
    WebSever web;
    web.addRoute("/",Response(login));
    web.addRoute("/ppp0",Response([](HttpRequest& resp){return GetRender->SendContent("/login.html");}));
    web.addRoute("/welcome",Response([](HttpRequest& resp){return  GetRender->SendHtml("/welcome.html");}));
    web.start();

}