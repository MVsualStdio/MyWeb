#ifndef PATH_H
#define PATH_H

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
#include <iostream>
using namespace std;

namespace web{
    class Config{
        private:
            static std::string getCwd();

        public:
            static const std::string ObjectDir;
            static const std::string SourceDir;
    };
    
    
}

#endif