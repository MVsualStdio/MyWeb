
// #include "Http/HttpServer.hpp"
// #include "Socket/Epolloop.hpp"

#include "WebServer.hpp"
#include "Login.hpp" 
using namespace web;
using namespace std;



// class Login: public ResponseCall{
//     public:
//         static ResponseCall::Ptr newPtr(){
//             return std::shared_ptr<Login>(new Login());

//         }
//         std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest req){
//             if(req.method() == HttpRequest::Method::kPost){
//                 unordered_map<string,string> parsebody =  req.postBody();
//                 auto res = GetSql->getQueryResult("web","web_user","user_name",parsebody["u"]).fetchOne();
//                 //std::cout<<res[2]<<std::endl;
//                 if(!res[2].isNull()  && res[2].get<string>() == parsebody["p"]){
//                     return GetRender->sendRedirect("/welcome.html");
//                 }
//             }
//             return GetRender->SendHtml("/login.html");
//         }
// };


// std::shared_ptr<HttpResponse> login(HttpRequest& req){
//     if(req.method() == HttpRequest::Method::kPost){
//         unordered_map<string,string> parsebody =  req.postBody();
//         auto res = GetSql->getQueryResult("web","web_user","user_name",parsebody["u"]).fetchOne();
//         //std::cout<<res[2]<<std::endl;
//         if(!res[2].isNull()  && res[2].get<string>() == parsebody["p"]){
//             return GetRender->sendRedirect("/welcome.html");
//         }
//     }
//     return GetRender->SendHtml("/login.html");
// }

int main(){
    GetSql->addQuery("web","web_user","user_name","wang");
    WebSever web;
    web.addRoute("/",Login::newPtr());
    //web.addRoute("/",Response::newPtr(login));
    web.addRoute("/ppp0",Response::newPtr([](HttpRequest& resp){return GetRender->SendContent("/login.html");}));
    web.addRoute("/welcome",Response::newPtr([](HttpRequest& resp){return  GetRender->SendHtml("/welcome.html");}));
    web.start();

}