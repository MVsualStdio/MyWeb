#include "../include/MysqlCon.hpp"
#include <unordered_map>
using namespace web;  

MysqlCon::MysqlCon(const std::string& url){
    sess = std::make_shared<mysqlx::Session>(url);
}

mysqlx::abi2::r0::RowResult MysqlCon::getQueryResult(const std::string& db,const std::string& table,const std::string& id,const std::string& content){
    mysqlx::abi2::r0::Table mytable = getTable(db,table);

    std::string query = id+"='" + content +"'";
    auto res = mytable.select().where(query).execute();
    return res;
}

bool MysqlCon::addQuery(const std::string& db,const std::string& table,const std::string& id,const std::string & content){
    bool ret=false;
    ;
    mysqlx::abi2::r0::Table mytable = getTable(db,table);

    std::string query = id+"='" + content +"'";
    auto tableRes = mytable.select().where(query).execute().fetchOne();
    if(tableRes.isNull()){
        mytable.insert(id,"user_paswd").values(content,"123").execute();
        ret = true;
    }
    return ret;
}  

mysqlx::abi2::r0::Table MysqlCon::getTable(const std::string& db,const std::string& table){
    mysqlx::Schema sch = sess->createSchema(db, true);
    mysqlx::abi2::r0::Table mytable = sch.getTable(table);
    return mytable;
}

