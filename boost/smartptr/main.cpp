#include<iostream>
#include<boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp> 
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <functional>
#include <boost/thread/thread.hpp>


void version1();
void version2();
void version3();
void version4();
void version5();

// A typedef to make the declarations below easier to read
typedef void (*WorkerFunPtr)( void*);
 
template<typename FunT,   // The type of the function being called
         typename ParamT> // The type of its parameter
struct Adapter {
   Adapter(FunT f, ParamT p) : // Construct this adapter and set the
      f_(f), p_(p) {}          // members to the function and its arg
 
   void operator( )( ) { // This just calls the function with its arg
      f_(p_);        
   }
private:
   FunT    f_;
   ParamT p_;  // Use the parameter's address to avoid extra copying
};




int main() {

    //version1();
    //version2();
    //version3();
    //version4();
    version5();

    return 0;
}



void worker_share(  void* pdata) {
    std::cout << "worker_share" << std::endl;

     boost::shared_ptr<int> *sh = static_cast< boost::shared_ptr<int>*>(pdata); 
    sh->reset(); 
   
}

void worker_weaker(  void* pdata) {
    std::cout << "worker_weaker" << std::endl;
     boost::weak_ptr<int> *w = static_cast< boost::weak_ptr<int>*>(pdata); 
    boost::shared_ptr<int> sh = w->lock(); 

    // this result decided to the order of two thread
    if (sh) {
        std::cout << "sh data:" << *sh << std::endl; 
    } else {
        std::cout << "sh nodata" << std::endl;
    }
        
}

void version5() {

    boost::shared_ptr<int> sh(new int(99)); 
    boost::weak_ptr<int> w(sh); 


    std::string s1 = "This is the first thread!";
    std::string s2 = "This is the second thread!";

    boost::thread thr1(Adapter<WorkerFunPtr, void* >(worker_share, &sh));
    boost::thread thr2(Adapter<WorkerFunPtr, void* >(worker_weaker, &w));

    thr1.join( );
    thr2.join( );
}

void version4() {
    boost::shared_array<int> i1(new int[2]); 
    boost::shared_array<int> i2(i1); 
    i1[0] = 1; 
    std::cout << i2[0] << std::endl; 
}

void version3() {
    std::vector<boost::shared_ptr<int> > v; 
    v.push_back(boost::shared_ptr<int>(new int(1))); 
    v.push_back(boost::shared_ptr<int>(new int(2))); 

    for(auto data : v) {
        std::cout << data << ":"<< *data << std::endl;
    }
}

void version2() {

    boost::scoped_array<int> i(new int[2]); 
    *i.get() = 1; 
    i[1] = 2; 

    for(int pos = 0; pos < 2; pos++) {
        std::cout << i[pos] << std::endl;
    }

    i.reset(new int[3]);
}

void version1() {
    boost::scoped_ptr<int> i(new int);
    
    *i = 100;
    std::cout << *i << std::endl;

    *i.get() = 200;
    std::cout << *i << std::endl;

    i.reset(new int);
    std::cout << *i << std::endl;
}

