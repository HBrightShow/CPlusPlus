#include <boost/bind.hpp> 
#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <boost/function.hpp> 
#include <cstdlib> 
#include <cstring>
#include <boost/lambda/lambda.hpp> 
#include <boost/lambda/if.hpp>

void version1();
void version2();
void version3();
void version4();
void version5();

void add(int i, int j) 
{ 
    std::cout << "i:" << i << ", j:" << j << std::endl; // i=10, j=1,3,2
  std::cout << i + j  << std::endl; 
} 

bool compare(int i, int j) 
{ 
  return i > j; 
} 

void add(int i, int j, std::ostream &os) 
{ 
  os << i + j << std::endl; 
} 

struct world 
{ 
  void hello(std::ostream &os) 
  { 
    os << "Hello, world!" << std::endl; 
  } 
};

int main() 
{ 
  //version1();
  //version2();
  //version3();
  //version4();
  version5();
}

void version5() {
    std::vector<int> v; 
    v.push_back(1); 
    v.push_back(3); 
    v.push_back(2); 

    //can't use std::endl;
    std::for_each(v.begin(), v.end(), std::cout << boost::lambda::_1 << "\n" );

    //output:3,2
    //others: boost::lambda::if_then_else() 和 boost::lambda::if_then_else_return() 
    std::for_each(v.begin(), v.end(), boost::lambda::if_then(boost::lambda::_1 > 1, std::cout << boost::lambda::_1 << "\n")); 
}

void version4() {
    boost::function<void (world*, std::ostream&)> f = &world::hello; 
    world w; 
    f(&w, boost::ref(std::cout));
}

void version3() {
    boost::function<int (const char*)> f = std::atoi; 
    std::cout << f("1609") << std::endl; 
    f = std::strlen; 
    std::cout << f("1609") << std::endl; 
}

void version2() {
    std::vector<int> v; 
    v.push_back(1); 
    v.push_back(3); 
    v.push_back(2); 

    //boost::bind() 的参数是以值方式传递,引用必须特别处理
    std::for_each(v.begin(), v.end(), boost::bind(add, 10, _1, boost::ref(std::cout)));
}

void version1() {
    std::vector<int> v; 
    v.push_back(1); 
    v.push_back(3); 
    v.push_back(2); 

    std::for_each(v.begin(), v.end(), boost::bind(add, 10, _1)); 

    std::sort(v.begin(), v.end(), boost::bind(compare, _2, _1));

    for(auto val : v) {
        std::cout << val << std::endl; //1,2,3
    }

    std::sort(v.begin(), v.end(), compare);

    for(auto val : v) {
        std::cout << val << std::endl;    // 3,2,1
    }
}