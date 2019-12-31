
/*
    code from net: http://zh.highscore.de/cpp/boost/interprocesscommunication.html
*/

#include<iostream>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp> 
#include <boost/interprocess/containers/string.hpp>

#include <boost/interprocess/sync/named_mutex.hpp> 
#include <boost/interprocess/sync/named_condition.hpp> 
#include <boost/interprocess/sync/scoped_lock.hpp>

namespace bip = boost::interprocess;

void version1();
void version2();
void version3();
void version4();
void version5();
void version6();
 
int main(int argc, char* argv[ ]) 
{
    //version1();
    //version2();
    //version3();
    //version4();
    version5();
    //version6()
}

void version6() {
     boost::interprocess::managed_shared_memory managed_shm(boost::interprocess::open_or_create, "shm", 1024); 
    int *i = managed_shm.find_or_construct<int>("Integer")(0); 
    boost::interprocess::named_mutex named_mtx(boost::interprocess::open_or_create, "mtx"); 
    boost::interprocess::named_condition named_cnd(boost::interprocess::open_or_create, "cnd"); 
    boost::interprocess::scoped_lock<boost::interprocess::named_mutex> lock(named_mtx); 
    while (*i < 10) 
    { 
        if (*i % 2 == 0) 
        { 
            ++(*i); 
            std::cout << "a++" << std::endl;
            named_cnd.notify_all(); 
            std::cout << "b++" << std::endl;
            named_cnd.wait(lock); 

            std::cout << "c++" << std::endl;
        } 
        else 
        { 
            std::cout << "d++" << std::endl;
            std::cout << *i << std::endl; 
            ++(*i); 
            named_cnd.notify_all(); 
            std::cout << "e++" << std::endl;
            named_cnd.wait(lock); 
            std::cout << "f++" << std::endl;
        } 
    } 
    named_cnd.notify_all(); 
    boost::interprocess::shared_memory_object::remove("shm"); 
    boost::interprocess::named_mutex::remove("mtx"); 
    boost::interprocess::named_condition::remove("cnd"); 
}

void version5() {
    boost::interprocess::managed_shared_memory managed_shm(boost::interprocess::open_or_create, "shm", 1024); 
    int *i = managed_shm.find_or_construct<int>("Integer")(); 
    boost::interprocess::interprocess_mutex *mtx = managed_shm.find_or_construct<boost::interprocess::interprocess_mutex>("mtx")(); 
    mtx->lock(); 
    ++(*i); 
    std::cout << *i << std::endl; 
    mtx->unlock(); 
}

void version4() {
    boost::interprocess::managed_shared_memory managed_shm(boost::interprocess::open_or_create, "shm", 1024); 
    int *i = managed_shm.find_or_construct<int>("Integer")(); 
    boost::interprocess::interprocess_mutex *mtx = managed_shm.find_or_construct<boost::interprocess::interprocess_mutex>("mtx")(); 
    mtx->lock(); 
    ++(*i); 
    std::cout << *i << std::endl; 
    mtx->unlock(); 

    managed_shm.destroy<int>("Integer");        //destory memory alloced
    std::pair<int*, std::size_t> p = managed_shm.find<int>("Integer");       
    std::cout << p.first << std::endl;          // output "0"
}

void version3() {

    bip::shared_memory_object::remove("Highscore"); 
    bip::managed_shared_memory managed_shm(bip::open_or_create, "Highscore", 1024); 
    typedef bip::allocator<char, bip::managed_shared_memory::segment_manager> CharAllocator; 
    typedef bip::basic_string<char, std::char_traits<char>, CharAllocator> string; 

    //note: the string of "sssss" decide the size of share memory
    string *s = managed_shm.find_or_construct<string>("String")("sssss", managed_shm.get_segment_manager()); 
    //s->insert(6, ", 1+++++");   //error ,why?
    s->insert(5, ", 2++++");
    s->insert(6, ", 3+++++"); 
    std::cout << *s << std::endl;
}

void version2() {

    bip::shared_memory_object::remove("Highscore"); 
    bip::managed_shared_memory managed_shm(bip::create_only, "Highscore", 1024); 
    int *i = managed_shm.construct<int>("Integer")[10](99); 
    std::cout << *i << std::endl;               // output "99"
    std::pair<int*, std::size_t> p = managed_shm.find<int>("Integer"); 
    if (p.first) 
    { 
        std::cout << *p.first << std::endl;     // output "99"
        std::cout << p.second << std::endl;     // output "10"
    } 

    managed_shm.destroy<int>("Integer");        //destory memory alloced
    p = managed_shm.find<int>("Integer");       
    std::cout << p.first << std::endl;          // output "0"

}

void version1() {
    try { 

    bip::shared_memory_object::remove("bright");

    // creating our first shared memory object.
    bip::shared_memory_object share_mem (bip::create_only, "bright", bip::read_write);

    std::cout << share_mem.get_name() << std::endl;
    
   
    

    // setting the size of the shared memory
    share_mem.truncate (256);
    bip::offset_t size; 
    if (share_mem.get_size(size)) 
        std::cout << size << std::endl;
    
    // map the shared memory to current process 
    bip::mapped_region mmap (share_mem, bip::read_write); 
    std::cout << std::hex << "0x" << mmap.get_address() << std::endl;
 
    // access the mapped region using get_address
    std::strcpy(static_cast<char* >(mmap.get_address()), "Hello ,bright!\n");
     
    } catch (bip::interprocess_exception& e) { 
        std::cout << e.what( ) << std::endl;
        
    } 

    //bip::shared_memory_object::remove("bright");
}