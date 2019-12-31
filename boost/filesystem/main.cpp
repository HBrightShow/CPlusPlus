#include<iostream>
#include<boost/filesystem.hpp>


void version1();
void version2();

int main() {
    
    //version1();
    version2();



    return 0;
}

void version2() {
    boost::filesystem::path p("test.txt"); 
    std::cout << p.stem() << std::endl;     //text
    std::cout << p.extension() << std::endl;    //.txt

    try 
    {
        boost::filesystem::file_status s = boost::filesystem::status(p);
        std::cout << boost::filesystem::is_directory(s) << std::endl;       //0

        std::cout << boost::filesystem::file_size(p) << std::endl;  //15

        std::time_t t = boost::filesystem::last_write_time(p);
        std::cout << std::ctime(&t) << std::endl;   //Wed Dec 11 14:07:16 2019

        boost::filesystem::space_info sp = boost::filesystem::space(p);
        std::cout << sp.capacity << std::endl;
        std::cout << sp.free << std::endl;
        std::cout << sp.available << std::endl;

        boost::filesystem::path d("hml"); 
        if(boost::filesystem::create_directory(d)) {
            boost::filesystem::rename(d, "bright");
        }
        else {
            boost::filesystem::remove("hml");
        }

        ///home/uos/hml/cplusplus/boost/filesystem/build/test.txt
        std::cout << boost::filesystem::complete("test.txt") << std::endl;

        ///home/uos/hml/cplusplus/boost/filesystem/build
        std::cout << boost::filesystem::current_path() << std::endl;

        //file stream
        boost::filesystem::path p("test.txt");
        boost::filesystem::ofstream ofs(p);
        ofs << "today is tuesday." << std::endl;
      

    }
    catch(boost::filesystem::filesystem_error &e) {
        std::cout << e.what() << std::endl;
    }
}


void version1() {
    boost::filesystem::path p("/home/uos");
    std::cout << p.string() << std::endl;
    //std::cout << p.file_string() << std::endl;  // no this function
    //std::cout << p.directory_string() << std::endl;   // no fuction

    std::cout << p.root_name() << std::endl; 
    std::cout << p.root_directory() << std::endl; 
    std::cout << p.root_path() << std::endl; 
    std::cout << p.relative_path() << std::endl; 
    std::cout << p.parent_path() << std::endl; 
    std::cout << p.filename() << std::endl;
    //output:
    /*
    /home/uos
    ""
    "/"
    "/"
    "home/uos"
    "/home"
    "uos"
    */
}