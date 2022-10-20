//author voidccc
#ifndef IMUDUOUSER_H
#define IMUDUOUSER_H

#include "Connectserver.hpp"
#include <string>

using namespace std;

namespace Net{
    class IMuduoUser{
        public:
            virtual void onConnection(Connectserver* pCon) = 0;
            virtual void onMessage(Connectserver* pCon, Buffer* pBuf) = 0;
            virtual void onWriteComplate(Connectserver* pCon) = 0;
    };
}


#endif
