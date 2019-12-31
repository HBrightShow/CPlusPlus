#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream> 
 
int main(int argc, char* argv[ ]) 
{
    using namespace boost::interprocess;
    try { 
      // creating a message queue
      message_queue mq (create_only,   // only create
                                       "mq",              // name
                                        20,                 //max message count
                                        sizeof(int)      //max message size
                                        );
      // now send the messages to the queue
      for (int i=0; i<20; ++i) 
        mq.send(&i, sizeof(int), 0); // the 3rd argument is the priority 

    
        sleep(100);
    } catch (interprocess_exception& e) { 
        std::cout << e.what( ) << std::endl;
    } 
}