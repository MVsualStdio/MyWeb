#ifndef MYSQLPOOL_H
#define MYSQLPOOL_H
#include <mysqlx/xdevapi.h>
#include "MysqlCon.hpp"
#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
namespace web{
    class MysqlPool{
        private:
            int nextRender_;
            int poolSize_;
            std::vector<std::shared_ptr<MysqlCon>> sqlPool_;
            std::condition_variable cond_;
            std::mutex mutex_;
            std::string url;
            MysqlPool(int poolSize=10);
        public:

            mysqlx::abi2::r0::RowResult getQueryResult(const std::string& db,const std::string& table,const std::string& content);
            static std::shared_ptr<MysqlPool> instance();
            std::shared_ptr<MysqlCon> GetSqler();
            void FreeRender(std::shared_ptr<MysqlCon>);
        public:
            #define GetSql MysqlPool::instance()->GetSqler()

    };
}



#endif
