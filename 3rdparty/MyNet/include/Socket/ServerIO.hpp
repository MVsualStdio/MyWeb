#ifndef SERVERIO_H
#define SERVERIO_H
#include<memory>
namespace Net{

    class ServerIO{
        public:
            virtual void serverRead()=0;
            virtual void serverWrite()=0;
            virtual void serverClose()=0;
    };

}

#endif