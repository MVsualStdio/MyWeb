#ifndef INDEX_H
#define INDEX_H
#include "web.hpp"
#include "Http/HttpRequest.hpp"


namespace web{
    using namespace Net;
    class Index: public web::ResponseCall{
    
        public:
            static ResponseCall::Ptr newPtr(){
                return std::shared_ptr<Index>(new Index());

            }
            std::shared_ptr<Net::HttpResponse> ResRun(Net::HttpRequest req){
                //blog-app/
                return GetRender->SendHtml("./favicon.ico");
            }
    };

}

#endif