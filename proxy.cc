
#include <boost/asio.hpp>
#include <memory>
#include <iostream>
#include <functional>
using namespace boost::asio;
const std::size_t BUF_SIZE = 100000;



class Session : public std::enable_shared_from_this<Session> {
public:
  Session(ip::tcp::socket socket,std::shared_ptr<boost::asio::ip::tcp::socket> proxy) 
    : socket_(std::move(socket)),proxy_(proxy) {
  }

  void Start() {
    DoRead();
  }

    void DoRead() {
        auto self(shared_from_this());
        socket_.async_read_some(
            boost::asio::buffer(buffer_),
            [this, self](boost::system::error_code ec, std::size_t length) {
                //std::cout<<std::string(buffer_.begin(),buffer_.begin()+20)<<std::endl;
                proxy_->write_some(boost::asio::buffer(buffer_,length));
                length = proxy_->read_some(boost::asio::buffer(buffer_));
                
                if (!ec) {
                    DoWrite(length);
                }
            });
    }

  void DoWrite(std::size_t length) {
    auto self(shared_from_this());
    boost::asio::async_write(
        socket_,
        boost::asio::buffer(buffer_, length),
        [this, self](boost::system::error_code ec, std::size_t length) {
          if (!ec) {
            DoRead();
          }
        });
  }

private:
  ip::tcp::socket socket_;
  std::array<char, BUF_SIZE> buffer_;
  std::shared_ptr<boost::asio::ip::tcp::socket> proxy_;
};


class Server {
public:
  Server(boost::asio::io_context& ioc, std::uint16_t port,std::string ip)
      : acceptor_(ioc, ip::tcp::endpoint(ip::tcp::v4(), port)) {
        
    ip::tcp::endpoint ep(ip::address::from_string(ip),6868);
    proxy = std::make_shared<boost::asio::ip::tcp::socket>(ioc);
    proxy->connect(ep);

    DoAccept();

  }

private:
  void DoAccept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, ip::tcp::socket socket) {
          if (!ec) {
            std::make_shared<Session>(std::move(socket),this->proxy)->Start();
          }
          DoAccept();
        });
    }

private:
  ip::tcp::acceptor acceptor_;
  std::shared_ptr<boost::asio::ip::tcp::socket> proxy;
};


// class Proxy{
//     public:
//         Proxy(boost::asio::io_context& ioc,std::uint16_t port,std::string ip){
//             ip::tcp::endpoint ep(ip::address::from_string(ip),port);
//             boost::asio::ip::tcp::socket sock(ioc);
//             ep.connect(sock);

//         }
//     private:
        
// };

int main(int argc, char* argv[]) {
  // if (argc != 2) {
  //   std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
  //   return 1;
  // }

  std::uint16_t port = 1110;

  boost::asio::io_context ioc;
  Server server(ioc, port,"127.0.0.1");

  ioc.run();
  return 0;
}