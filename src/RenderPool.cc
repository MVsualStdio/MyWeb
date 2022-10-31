#include "RenderPool.hpp"


using namespace web;

RenderPool::RenderPool(int poolSize):poolSize_(poolSize){
    renderPool_.resize(poolSize_);
    for(int i=0;i<poolSize_;++i){
        renderPool_[i] = make_shared<Render>();
    }
}

std::shared_ptr<Render> RenderPool::getRender(){
    std::shared_ptr<Render> res;
    {
        std::unique_lock<mutex> locker(mutex_);
        for(int i=0;i<poolSize_;++i){
            if(renderPool_[i].use_count() == 1){
                res = renderPool_[i];
                //std::cout<<i<<std::endl;
                break;

            }
        }
    }
    if(res == nullptr){
        res = make_shared<Render>();
        {
            std::unique_lock<mutex> locker(mutex_);
            poolSize_ += 1;
            renderPool_.resize(poolSize_);
            renderPool_[poolSize_] = res;
        }
    }
    return res;
}

// void RenderPool::FreeRender(std::shared_ptr<Render> render){
//     std::unique_lock<mutex> locker(mutex_);
//     renderPool_.push(render);
//     cond_.notify_one();
// }
std::shared_ptr<RenderPool> RenderPool::instance(){

    static std::shared_ptr<RenderPool> Pool(new RenderPool(10));
    return Pool;
}