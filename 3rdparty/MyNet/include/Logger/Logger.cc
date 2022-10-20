#include "./Logger.hpp"


using namespace Net;

Logger::Logger(){
    //Task* task =  new Task(writeThread);
    std::thread(writeThread);

    auto time = chrono::system_clock::now();
    time_t tm = chrono::system_clock::to_time_t(time);
    string ts = ctime(&tm);
    ts.resize(ts.size() - 1); 
    std::string path;
    path = getcwd(NULL,0);
    std::cout<<"PATH"<<path<<std::endl;
    string file = "../Log/"+ts+".log";
    std::cout<<"Log File:"<<file<<std::endl;
    os.open(file,ios::out|ios::app);

    logstream = new LoggerStream(ss);
}

Logger::~Logger(){
    flush();
    os.close();
    delete logstream;
}

void Logger::flush(){
    if(!ss.str().empty()){
        string buf = ss.str();
        bufQue.push({_level,buf});
        ss.str("");
        os.flush();
        logstream->flush();
    }
}

Logger* Logger::instance(){
    static Logger logger;
    return &logger;
}

LoggerStream* Logger::steam(){
     return logstream;
}


void Logger::setLevel(LEVEL level){
    _level = level;
}

void Logger::writeThread(){
    int currenLogNum = 0;
    while(1){
        auto res = bufQue.pop();
        if(res.first == LEVEL::MESSAGE){
            os << "[message] ";
        }

        if(res.first == LEVEL::WARN){
            os << "[warnning] ";
        }

        auto time = chrono::system_clock::now();
        time_t tm = chrono::system_clock::to_time_t(time);
        string ts = ctime(&tm);
	    ts.resize(ts.size() - 1); 
        os << ts <<": ";
        os << res.second << endl;
        flush();
        ++currenLogNum;
        if(currenLogNum == 100000){
            os.close();
            string file = "./Log/"+ts+".log";
            os.open(file,ios::out|ios::app);
            currenLogNum = 0;
        }
        sleep(2);
    }
}