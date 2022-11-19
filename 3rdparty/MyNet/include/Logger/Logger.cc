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

string Logger::getLogDate(){
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
    return ts.assign(0+ts.begin(),t);
}



void Logger::logInit(string dir, int count)
{

    dir_ = dir;
    count_ = count;
    bufferPool = make_shared<Queue<std::shared_ptr<Buffer>>>();

    initFileName();
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

        curCount_ = temp.size()+curCount_; 
        // std::cout<<curCount_<<std::endl;
        out_.flush();
        sleep(1);
    }
}

Logger::~Logger(){
    out_.close();
}

void Logger::mkLogFile(){

    string ts = getLogDate();
    struct stat buffer;   
    int lognum = 0;
    while(1){
        fileName = dir_ + "/" + ts + "." + std::to_string(lognum) + ".log";
        if(stat (fileName.c_str(), &buffer) == 0){
            ++lognum;
        }
        else{
            break;
        }
    }
    curCount_ = 0;
    std::cout<<"fileName"<<fileName<<std::endl;
    out_.close();
    out_.open(fileName, ios::app);
}


void Logger::initFileName(){
    string ts = getLogDate();
    struct stat buffer;   
    int lognum = 0;
    while(1){
        fileName = dir_ + "/" + ts + "." + std::to_string(lognum) + ".log";
        if(stat (fileName.c_str(), &buffer) == 0){
            ++lognum;
        }
        else{
            break;
        }
    }

    if(lognum == 0){
        out_.open(fileName, ios::app);
        curCount_ = 0;
    }
    else{
        string oldfileName = dir_ + "/" + ts + "." + std::to_string(lognum-1) + ".log";
        ifstream ReadFile(oldfileName);
        string tmp;
        while (getline(ReadFile, tmp, '\n')){
			curCount_++;
		}
        if(curCount_ <= count_ ){
            lognum = lognum -1;
            fileName =  oldfileName;
        }
        out_.open(fileName, ios::app);
    }
    
}