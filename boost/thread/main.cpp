#include <boost/thread.hpp> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <ctime> 

void wait(int seconds) 
{ 
  boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
} 

void thread1() 
{ 
  for (int i = 0; i < 5; ++i) 
  { 
    wait(1); 
    std::cout << i << std::endl; 
  } 
} 
void thread2() 
{ 
  try 
  { 
    for (int i = 0; i < 5; ++i) 
    { 
      wait(1); 
      std::cout << i << std::endl; 
    } 
  } 
  catch (boost::thread_interrupted& ex) 
  { 
      std::cout << "thread_interrupted" << std::endl;   // will be output
  } 
} 

void version1();
void version2();
void version3();
void version4();
void version5();
void version6();
void version7();
void version8();

int main() 
{ 
    //version1();
    //version2();
    //version3();
    //version4();
    //version5();
    //version6();
    //version7();
    version8();
 
    return 0;
}

boost::mutex mutex_8;
boost::condition_variable_any cond_8;
std::vector<int> random_numbers;

void fill_8() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    for(int i = 0; i <3; ++i) {
        boost::unique_lock<boost::mutex> lock(mutex_8);
        random_numbers.push_back(std::rand());
        cond_8.notify_all();
        cond_8.wait(mutex_8);
    }
}

void print_8() {
    std::size_t next_size = 1;
    for(int i= 0; i < 3; ++i) {
        boost::unique_lock<boost::mutex> lock(mutex_8);
        while(random_numbers.size() != next_size)
            cond_8.wait(mutex_8);
        
        std::cout << random_numbers.back() << std::endl;
        ++next_size;
        cond_8.notify_all();
    }
}


void version8() {
    boost::thread t1(fill_8); 
    boost::thread t2(print_8); 
    t1.join(); 
    t2.join();
}

boost::shared_mutex mutex_7; 
//std::vector<int> random_numbers; 

void fill() 
{ 
  std::srand(static_cast<unsigned int>(std::time(0))); 
  for (int i = 0; i < 3; ++i) 
  { 
    boost::unique_lock<boost::shared_mutex> lock(mutex_7); 
    random_numbers.push_back(std::rand()); 
    lock.unlock(); 
    wait(1); 
  } 
} 

void print() 
{ 
  for (int i = 0; i < 3; ++i) 
  { 
    wait(1); 
    boost::shared_lock<boost::shared_mutex> lock(mutex_7); 
    std::cout << random_numbers.back() << std::endl; 
  } 
} 

int sum = 0; 

void count() 
{ 
  for (int i = 0; i < 3; ++i) 
  { 
    wait(1); 
    boost::shared_lock<boost::shared_mutex> lock(mutex_7); 
    sum += random_numbers.back(); 
  } 
} 

void version7() {
    boost::thread t1(fill); 
    boost::thread t2(print); 
    boost::thread t3(count); 
    t1.join(); 
    t2.join(); 
    t3.join(); 
    std::cout << "Sum: " << sum << std::endl; 
}

boost::timed_mutex mutex_time; 

void thread6() 
{ 
  for (int i = 0; i < 5; ++i) 
  { 
    wait(1); 
    boost::unique_lock<boost::timed_mutex> lock(mutex_time, boost::try_to_lock); 
    if (!lock.owns_lock()) //waiting for 1s to get the lock
      lock.timed_lock(boost::get_system_time() + boost::posix_time::seconds(2)); 
    std::cout << "Thread " << boost::this_thread::get_id() << ": " << i << std::endl; 
    boost::timed_mutex *m = lock.release(); 
    wait(1);
    m->unlock(); 
  } 
} 


void version6() {
    boost::thread t1(thread6); 
    boost::thread t2(thread6); 
    t1.join(); 
    t2.join(); 
}





boost::mutex mutex; 

void thread4() 
{ 
  for (int i = 0; i < 5; ++i) 
  { 
    wait(1); 
    boost::lock_guard<boost::mutex> lock(mutex); 
    std::cout << "Thread " << boost::this_thread::get_id() << ": " << i << std::endl; 
  } 
} 

void version5() {
    boost::thread t1(thread4); 
    boost::thread t2(thread4); 
    t1.join(); 
    t2.join();
}

void thread3() 
{ 
  for (int i = 0; i < 5; ++i) 
  { 
    wait(1); 
    mutex.lock(); 
    std::cout << "Thread " << boost::this_thread::get_id() << ": " << i << std::endl; 
    mutex.unlock(); 
  } 
} 

void version4() {
    boost::thread t1(thread3); 
    boost::thread t2(thread3); 
    t1.join(); 
    t2.join(); 
}

void version3() {
    std::cout << boost::this_thread::get_id() << std::endl;     //thread id
    std::cout << boost::thread::hardware_concurrency() << std::endl;    //cpu core number
}

void version2() {
    boost::thread t(thread2);
    wait(3);
    //t.detach();       //invalid?
    t.interrupt();
    t.join();
}

void version1() {
    boost::thread t(thread1); 
    t.join(); 
}