#ifndef LOGIN_H
#define LOGIN_H
#include "Route.hpp"
#include "Render.hpp"
#include "Http/HttpRequest.hpp"
#include "RenderPool.hpp"
#include "MysqlPool.hpp"

namespace web{
    using namespace Net;
    class Login: public web::ResponseCall{
    
        public:
            static ResponseCall::Ptr newPtr(){
                return std::shared_ptr<Login>(new Login());

            }
            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest req){
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
    };

}

#endif