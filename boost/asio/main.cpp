#include<iostream>
#include<boost/asio.hpp>
#include<boost/thread.hpp>
#include<boost/array.hpp>



void version1();
void version2();
void version3();
void version4();
void version5();  // web client
void version6();


int main() {
    //version1();
    //version2();
    //version3();
    //version4();
    version5();
    //version6();

    return 0;
}


boost::asio::io_service io_service;
boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 8001);
boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
boost::asio::ip::tcp::socket sock(io_service);
std::string data = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, bright!";

void write_handler(const boost::system::error_code &ec, std::size_t bytes_transferred) {

}

void accept_handler(const boost::system::error_code &ec) {
    if(!ec) {
        boost::asio::async_write(sock, boost::asio::buffer(data), write_handler);
    }
}

//test by curl:    curl http://127.0.0.1:8001
void version6() {
    acceptor.listen();
    acceptor.async_accept(sock, accept_handler);
    io_service.run();
}

//boost::asio::io_service io_service;
boost::asio::ip::tcp::resolver resolver(io_service);
//boost::asio::ip::tcp::socket sock(io_service);
boost::array<char, 4096> buffer;

void read_handler(const boost::system::error_code &ec, std::size_t bytes_transferred) {
    if(!ec) {
        std::cout << std::string(buffer.data(), bytes_transferred) << std::endl;
        sock.async_read_some(boost::asio::buffer(buffer), read_handler);
    }
}

void connect_handler(const boost::system::error_code &ec) {
    if(!ec) {
        boost::asio::write(sock, boost::asio::buffer("GET / HTTP 1.1\r\nHost:: highscore.de\r\n"));
        sock.async_read_some(boost::asio::buffer(buffer), read_handler);
    }
}

void resolve_handler(const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator it) {
    if(!ec) {
        sock.async_connect(*it, connect_handler);
    }
}

void version5() {
    boost::asio::ip::tcp::resolver::query query("www.highscore.de", "80");
    resolver.async_resolve(query, resolve_handler);
    io_service.run();
}


void handler1(const boost::system::error_code &ec) 
{ 
  std::cout << "5 s." << std::endl; 
  sleep(2);
} 

void handler2(const boost::system::error_code &ec) 
{ 
  std::cout << "5 s again." << std::endl; 
} 

boost::asio::io_service io_service1; 
boost::asio::io_service io_service2;
void run1() 
{ 
  io_service1.run(); 
} 

void run2() 
{ 
  io_service2.run(); 
} 
void version4() {
    boost::asio::deadline_timer timer1(io_service1, boost::posix_time::seconds(5)); 
    timer1.async_wait(handler1); 
    boost::asio::deadline_timer timer2(io_service2, boost::posix_time::seconds(5)); 
    timer2.async_wait(handler2); 
    boost::thread thread1(run1); 
    boost::thread thread2(run2); 
    thread1.join(); 
    thread2.join();
}

//boost::asio::io_service io_service; 

void run() 
{ 
  io_service.run(); 
} 

//this method will lead to std::cout shared and output bad
void version3() {
    boost::asio::deadline_timer timer1(io_service, boost::posix_time::seconds(5)); 
    timer1.async_wait(handler1); 
    boost::asio::deadline_timer timer2(io_service, boost::posix_time::seconds(5)); 
    timer2.async_wait(handler2); 
    boost::thread thread1(run); 
    boost::thread thread2(run); 
    thread1.join(); 
    thread2.join();
}


void version2() {
    boost::asio::io_service io_service; 
    boost::asio::deadline_timer timer1(io_service, boost::posix_time::seconds(5)); 
    timer1.async_wait(handler1); 
    boost::asio::deadline_timer timer2(io_service, boost::posix_time::seconds(5)); 
    timer2.async_wait(handler2); 

    //note:the order : handler1  -> handler2. so handler2 is used afer 7s
    
    io_service.run();
}

void handler_1(const boost::system::error_code & ec) {
    std::cout << "5s elapse !" << std::endl;
}

void version1() {
    boost::asio::io_service io_service;
    boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
    timer.async_wait(handler_1);
    io_service.run();
}