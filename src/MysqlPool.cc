#include "../include/MysqlPool.hpp"


using namespace web;

MysqlPool::MysqlPool(int poolSize):poolSize_(poolSize){
    sqlPool_.resize(poolSize_);
    url = "mysqlx://xie:123456@127.0.0.1:33060";
    for(int i=0;i<poolSize_;++i){
        sqlPool_[i] = std::make_shared<MysqlCon>(url);
    }
}


std::shared_ptr<MysqlCon> MysqlPool::GetSqler(){
    std::shared_ptr<MysqlCon> res;
    {
        std::unique_lock<std::mutex> locker(mutex_);
        for(int i=0;i<poolSize_;++i){
            if(sqlPool_[i].use_count() == 1){
                res = sqlPool_[i];
                break;
            }
        }
    }
    return res;
}

// void RenderPool::FreeRender(std::shared_ptr<Render> render){
//     std::unique_lock<mutex> locker(mutex_);
//     renderPool_.push(render);
//     cond_.notify_one();
// }

std::shared_ptr<MysqlPool> MysqlPool::instance(){
    static std::shared_ptr<MysqlPool> Pool(new MysqlPool(10));
    return Pool;
}
