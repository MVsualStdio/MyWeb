#include "Config.hpp"



using namespace web;

std::string Config::getCwd(){
    char* srcDir_ = getcwd(nullptr, 256);
    std::string  SourceDir = std::string(srcDir_);
    free(srcDir_);
    return SourceDir;
}



const std::string Config::ObjectDir = Config::getCwd();
const std::string Config::SourceDir = ObjectDir + "/static/";




