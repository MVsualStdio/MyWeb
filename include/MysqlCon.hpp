#ifndef MYSQLCON_H
#define MYSQLCON_H

#include <mysqlx/xdevapi.h>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
#include <iostream>
namespace web{
    class MysqlCon{
        private:
            std::shared_ptr<mysqlx::Session> sess;
        public:
            MysqlCon(const std::string& url);
            mysqlx::abi2::r0::Table getTable(const std::string& db,const std::string& table);
            mysqlx::abi2::r0::RowResult getQueryResult(const std::string& db,const std::string& table,const std::string& id,const std::string& content);
            bool addQuery(const std::string& db,const std::string& table,const std::string& id,const std::string& content);
    };
}



#endif
