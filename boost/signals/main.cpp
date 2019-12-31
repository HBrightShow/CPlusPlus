#include<iostream>
#include<boost/signals2.hpp>


void version1();
void version2();
void version3();
void version4();

int func1() 
{ 
  return 1; 
} 

int func2() 
{ 
  return 2; 
} 


void sam() {
    std::cout << "sam good!" << std::endl;
}

void bright() {
    std::cout << "bright good!" << std::endl;
}



int main() {
    //version1();
    //version2();
    //version3();
    version4();

    return 0;
}

void version4() {
     boost::signals2::signal<void ()> s; 
    { 
        boost::signals2::scoped_connection c = s.connect(sam); 
    } 
    s();    // not wrok 
}

// error test
/*
void version3() {
    boost::signals2::signal<void ()> s; 
    boost::signals2::connection c = s.connect(sam); 
    c.block();      // 
    s();        // not work
    c.unblock(); 
    s(); 
}
*/



template <typename T> 
struct min_element 
{ 
  typedef T result_type; 

  template <typename InputIterator> 
  T operator()(InputIterator first, InputIterator last) const 
  { 
    return T(first, last); 
  } 
}; 

void version2() {
    boost::signals2::signal<int (), min_element<std::vector<int> > > s; 
    s.connect(func1); 
    s.connect(func2); 
    std::vector<int> v = s(); 
    
    for(auto val : v) {
        std::cout << val << std::endl;  // 1, 2
    }
}

void version1() {
    boost::signals2::signal<void ()> s;
    s.connect(sam);
    s.connect(bright);
    s.disconnect(sam);  //disconnect_all_slots()
    std::cout << s.num_slots() << std::endl;        //  1
    s();
}