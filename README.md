### http服务器
#### 介绍：
1. 拥有三个线程，一个TCP Accept,2个处理http读写任务线程
2. 支持Get，Post方法，post只支持一种回应
3. static文件夹，包括html，css，js，静态文件分别写入对应文件夹
4. 3rdparty中的MyNet模仿现成的muduo等网络库mini版本。
5. web.cc是入口函数 run.sh是启动命令，除了std未采用其他库。
6. http端口6868，之后用json解析(todo)
7. sql连接 (todo)
8. psot支持多种回应 (todo)  
#### 环境：
- Linux16.04 云服务器
- cmake


#### Introduction:
1. The http server has three thread to process task,one processes how to accept ,the others is to process I/0.
2. Support GET POST method.
3. static folder include html,css,js;static file write different folder.
4. MyNet in 3rdparty imitates muduo-Net of mini.
5. web.cc is main function,run.sh is running script.
6. http port is 6868.

