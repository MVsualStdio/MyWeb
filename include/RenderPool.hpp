#ifndef RENDERPOOL_H
#define RENDERPOOL_H
#include "Render.hpp"
#include <condition_variable>
#include <mutex>
#include <queue>
namespace web{
    class RenderPool{
        private:
            int nextRender_;
            int poolSize_;
            std::vector<std::shared_ptr<Render>> renderPool_;
            std::condition_variable cond_;
            std::mutex mutex_;
            RenderPool(int poolSize=10);
        public:
            static std::shared_ptr<RenderPool> instance();
            std::shared_ptr<Render> getRender();
            void FreeRender(std::shared_ptr<Render>);
        public:
            #define GetRender RenderPool::instance()->getRender()

    };
}



#endif
