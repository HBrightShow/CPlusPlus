#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstring>
#include <cstdlib>
#include <iostream>

void version1();
 
int main(int argc, char *argv[ ])
{
    version1();


      return 0;
}

void version1() {
    using namespace boost::interprocess; 
      try { 
        // opening an existing shared memory object 
        shared_memory_object sharedmem2 (open_only, "bright", read_write);
    
        // map shared memory object in current address space
        mapped_region mmap (sharedmem2, read_write);
    
        // need to type-cast since get_address returns void* 
        char *str1 = static_cast<char*> (mmap.get_address());
        std::cout << str1 << std::endl;

        std::strcpy(static_cast<char* >(mmap.get_address()), "Hello ,get!\n");
        //shared_memory_object::remove("bright");

      } catch (interprocess_exception& e) { 
          std::cout << e.what( ) << std::endl;
      } 

}