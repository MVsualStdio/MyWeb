#ifndef WORKITEM
#define WORKITEM


namespace Net{
    class WorkItem{
        public:
            virtual void run()=0;
    };
}

#endif