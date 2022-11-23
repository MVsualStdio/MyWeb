#ifndef LOGIN_H
#define LOGIN_H
#include "Route.hpp"
#include "Render.hpp"
#include "Http/HttpRequest.hpp"
#include "RenderPool.hpp"
#include "MysqlPool.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace web{
    using namespace Net;
    class Login: public web::ResponseCall{
    
        public:
            static ResponseCall::Ptr newPtr(){
                return std::shared_ptr<Login>(new Login());

            }
            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest req){
                json response;
                response["state"] = false;

                if(req.method() == HttpRequest::Method::kPost){
                    unordered_map<string,string> parsebody =  req.postBody();
                    response["name"] = parsebody["username"];
                    auto res = GetSql->getQueryResult("web","web_user","user_name",parsebody["username"]).fetchOne();
                    //  std::cout<<parsebody["username"]<<std::endl;
                    if(!res[2].isNull()  && res[2].get<string>() == parsebody["password"]){
                        std::cout<<res[1].get<string>()<<"  "<<res[2].get<string>()<<std::endl;
                        response["state"] = true;
                        // return GetRender->SendHtml("/secret/index.html");
                        // return GetRender->sendRedirect("/welcome.html");
                    }
                }
                return GetRender->SendContent(response.dump(),RenderType::ResponseType::json);
            }
    };

}

#endif