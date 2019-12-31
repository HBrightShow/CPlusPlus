#include<iostream>
#include <boost/system/error_code.hpp> 
#include <boost/asio.hpp> 


void version1();
void version2();

int main() {

    //version1();
    version2();

    return 0;
}

class applicatin_category : public boost::system::error_category
{

public:
    const char* name() const noexcept { return "application"; }
     std::string message(int ev) const { return "error message"; }

};
applicatin_category cat;

void version2() {
    boost::system ::error_code     ec(14, cat);
    std::cout << ec.value() << std::endl;
    std::cout << ec.category().name() << std::endl;
}


void version1() {
    boost::system::error_code ec; 
    std::string hostname = boost::asio::ip::host_name(ec); 

    std::cout << hostname << std::endl;     // hml
    std::cout << ec.value() << std::endl; // 0

    std::cout << ec.category().name() << std::endl; // system
}