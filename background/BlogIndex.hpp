#ifndef BLOGLIST_H
#define BLOGLIST_H
#include "web.hpp"
#include "Http/HttpRequest.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace web{
    using namespace Net;
    class BlogIndex: public web::ResponseCall{
    
        public:
            static ResponseCall::Ptr newPtr(){
                return std::shared_ptr<BlogIndex>(new BlogIndex());

            }
            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest req){
                json data;

                //json dataObj = json::array({});
                
                data["blogLists"] = json::array();
                json jsonObj = {{"title",123}};
                json jsonObj2 = {{"title",456}};
                data["blogLists"].push_back(jsonObj);
                data["blogLists"].push_back(jsonObj2);
                data["blogCategory"] = 1;
                data["blogArticle"] = 2;
                // std::string s = "{\"blogLists\":[{\"title\":123},{\"title\":456}],\"blogCategory\":1,\"blogArticle\":2}";

                return GetRender->SendContent(data.dump(),RenderType::ResponseType::json);
            }
    };

}

#endif