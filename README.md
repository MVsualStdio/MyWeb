## C++ simple Web Server

### http服务器
#### 介绍：
1. 拥有多个线程，一个TCP Accept,n个处理http读写任务线程,n可在config配置
2. 支持Get，Post方法，post只支持一种回应
3. 静态文件需要放在static文件夹中。
4. 3rdparty中的MyNet模仿现成的muduo等网络库自己手写的mini版本。
5. web.cc是入口函数 run.sh是启动命令，除了std未采用其他库。
6. http端口6868，用Config.json配置解析
7. sql连接
8. psot支持json 和 文本
9. 支持hexo的前端生成
10. 定时器(todo)
    
#### 环境：
- Linux16.04 云服务器
- cmake
- Mysql8
- 可使用NOSQL版本,删除3rdparty的mysql,删除include/MysqlPool.hpp,src/MysqlPool.cc  
    CMakeLists.txt
    ```
        set(MYSQLDIR ${PROJECT_SOURCE_DIR}/3rdparty/mysql-connector-c++-8.0.31)
        include_directories(${MYSQLDIR}/include)
        link_libraries(${MYSQLDIR}/lib64/libmysqlcppconn8.so)
    ```
#### hexo配置
1. 下载hexo到当前文件夹([hexo下载文档](https://hexo.io/zh-cn/docs/index.html))
    ```
    cd MyWeb
    npm install hexo
    ```
2. 更改hexo文件下的_config.yml更改配置
    ```
    #找到配置
    public_dir: ../static
    ```
3. hexo使用说明见[hexo文档](https://hexo.io/zh-cn/docs/index.html),生成静态文件
    ```
        cd hexo
        hexo clean
        hexo g
    ```


#### Introduction:
1. The http server has three thread to process task,one processes how to accept ,the others is to process I/0.
2. Support GET POST method.
3. static folder include html,css,js;static file write different folder.
4. MyNet in 3rdparty imitates muduo-Net of mini.
5. web.cc is main function,run.sh is running script.
6. http port is 6868.
7. mysql can be connected
8. post function supports json and text
9. hexo is supported


#### hexo config