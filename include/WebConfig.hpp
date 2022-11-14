#ifndef WEBCONFIG_H
#define WEBCONFIG_H

#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
namespace web{
    class Config{
        private:
            static std::ifstream in;
            static std::string getCwd(){
                char* srcDir_ = getcwd(nullptr, 256);
                std::string  source = std::string(srcDir_);
                free(srcDir_);
                return source;
            }
        public:
            static const std::string ObjectDir;
            static const std::string SourceDir;
            static const json data;
            static const int port;
            static const int numThread;
            static const int BufferMaxLen;
    };

}

#endif
