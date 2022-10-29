#ifndef BLOGLIST_H
#define BLOGLIST_H
#include "web.hpp"
#include "Http/HttpRequest.hpp"

namespace web{
    using namespace Net;
    class BlogList: public web::ResponseCall{
    
        public:
            static ResponseCall::Ptr newPtr(){
                return std::shared_ptr<BlogList>(new BlogList());

            }
            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest req){
                std::string s = "{\"name\":\"xie\",\"age\":18}";
                return GetRender->SendContent(s,RenderType::ResponseType::json);
            }
    };

}

#endif