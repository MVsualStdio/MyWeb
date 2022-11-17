#include "Logger.hpp"

using namespace Net;

const std::unordered_map<Logger::LEVEL, string> Logger::levelMap{
    {Logger::LEVEL::MESSAGE, "[message]"},
    {Logger::LEVEL::WARN, "[warn]"},
    {Logger::LEVEL::DEBUG, "[debug]"},
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
    bufferPool = make_shared<Queue<std::shared_ptr<Buffer>>>();
    auto time = chrono::system_clock::now();
    
    time_t tm = chrono::system_clock::to_time_t(time);
    string ts = ctime(&tm); 
    int spaceCount = 0;
    auto t = ts.begin();
    for(;t!=ts.end();++t){
        if(*t == ' '){
            ++spaceCount;
        }
        if(spaceCount == 3){
            break;
        }
    }

    mkLogFile();

    std::shared_ptr<Task> task(new Task(&Logger::writeThread, this));
    ThreadPool::instance()->addTask(task);
}


void Logger::writeThread()
{
    while (1)
    {
        if(curCount_ >= count_){
            mkLogFile();
        }
        queue<std::shared_ptr<Net::Buffer>> temp;

        bufferPool->swap(temp);
        for(int i=0;i<temp.size();++i){
            std::shared_ptr<Net::Buffer> b = temp.front();
            temp.pop();
            out_ << string(b->peek(),b->end()) << endl;
        }
        out_.flush();
        sleep(1);
    }
}

Logger::~Logger(){
    out_.close();
}

void Logger::mkLogFile(){
    auto time = chrono::system_clock::now();
    time_t tm = chrono::system_clock::to_time_t(time);
    string ts = ctime(&tm); 
    int spaceCount = 0;
    auto t = ts.begin();
    for(;t!=ts.end();++t){
        if(*t == ' '){
            ++spaceCount;
        }
        if(spaceCount == 3){
            break;
        }
    }

    string filename = dir_ + "/" + ts.assign(0+ts.begin(),t) + ".log";
    ifstream ReadFile;
	int n = 0;
	string tmp;
    int i = 1;
    while(i){
        ReadFile.open(filename, ios::in);//ios::in 表示以只读的方式读取文件  
        if (ReadFile.fail()){
            curCount_ =  0;
        }
        else{
            while (getline(ReadFile, tmp, '\n')){
                curCount_++;
            }
            ReadFile.close();
        }

        if(curCount_==0 ||  curCount_ <= count_){
            out_.open(filename, ios::app);
            break;
        }
        else{
            filename = filename + "." + to_string(i) ;
        }   
    }
	
}