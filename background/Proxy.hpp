#ifndef PROXY_H
#define PROXY_H
#include "Route.hpp"
#include "Render.hpp"
#include "Http/HttpRequest.hpp"
#include "RenderPool.hpp"
#include "MysqlPool.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace web{
    using namespace Net;
    class Proxy: public web::ResponseCall{
    
        public:
            static ResponseCall::Ptr newPtr(){
                return std::shared_ptr<Proxy>(new Proxy());

            }
            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest req){
                json response;
                response["state"] = false;
                return GetRender->SendContent(response.dump(),RenderType::ResponseType::json);
            }
    };

}

#endif