#include "NewLogger.hpp"

using namespace Net;

const std::map<Logger::LEVEL, string> Logger::levelMap{
    {Logger::LEVEL::MESSAGE, "[message]"},
    {Logger::LEVEL::WARN, "[warn]"},
};

Logger *Logger::instance()
{
    static Logger logger;
    return &logger;
}

void Logger::logInit(string dir, int count)
{

    dir_ = dir;
    count_ = count;
    auto time = chrono::system_clock::now();
    time_t tm = chrono::system_clock::to_time_t(time);
    string ts = ctime(&tm);
    ts.resize(ts.size() - 1);
    out_.open(dir_ + "/" + ts + ".log", ios::app);

    std::shared_ptr<Task> task(new Task(&Logger::writeThread, this));
    ThreadPool::instance()->addTask(task);
}

template <class T, class... Args>
void Logger::write_log(LEVEL level, const T &t, const Args &...args)
{
    std::shared_ptr<Buffer> s(new Buffer());
    s->append(levelMap[level]);
    p_write_log(s, t, args...);
    bufferPool.push(s);
}

template <class T, class... Args>
void Logger::p_write_log(std::shared_ptr<Buffer> s, const T &t, const Args &...args)
{
    s->append(t);
    p_write_log(s, args...);
}

template <class T>
void Logger::p_write_log(std::shared_ptr<Buffer> s, const T &t)
{
    s->append(t);
}

void Logger::writeThread()
{
    while (1)
    {
        Net::Queue<std::shared_ptr<Net::Buffer>> temp;
        bufferPool.swap(temp);
        for(int i=0;i<temp.size();++i){
            std::shared_ptr<Net::Buffer> b = temp.pop();
            out_ << b->peek() << endl;
        }
        out_.flush();
        sleep(1);
    }
}
