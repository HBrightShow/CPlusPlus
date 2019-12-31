#include<iostream>
#include<locale>
#include<boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include<string>

void version1();
void version2();
void version3();
void version4();
void version5();
void version6();
void version7();
void version8();
void version9();
void version10();
void version11();
void version12();
void version13();
void version14();
void version15();

int main() {
    //version1();
    //version2();
    //version3();
    //version4();
    //version5();
    //version6();
    //version7();
    //version8();
    //version9();
    //version10();
    //version11();
    //version12();
    //version13();
     //version14();
     version15();

    return 0;
}

void version15() {
     typedef boost::tokenizer<boost::offset_separator> tokenizer; 
    std::string s = "Boost C++ libraries"; 
    int offsets[] = { 5, 5, 9 }; 
    boost::offset_separator sep(offsets, offsets + 3); 
    tokenizer tok(s, sep); 
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) 
        std::cout << *it << std::endl;

    //output
    /*
    Boost
    C++ 
    libraries

    */
}

//csv file
void version14() {
    typedef boost::tokenizer<boost::escaped_list_separator<char> > tokenizer; 
    std::string s = "Boost,\"C++ libraries\""; 
    tokenizer tok(s); 
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) 
        std::cout << *it << std::endl; 

    //output:
    /*
    Boost
    C++ libraries
    */
}

void version13() {
    typedef boost::tokenizer<boost::char_separator<wchar_t>, std::wstring::const_iterator, std::wstring> tokenizer; 
    std::wstring s = L"Boost C++ libraries"; 
    boost::char_separator<wchar_t> sep(L" "); 
    tokenizer tok(s, sep); 
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) 
        std::wcout << *it << std::endl;

    //output
    /*
    Boost
    C++
    libraries
    */
}

void version12() {
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer; 
    std::string s = "Boost C++ libraries"; 
    boost::char_separator<char> sep(" ", "+"); 
    tokenizer tok(s, sep); 
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) 
        std::cout << *it << std::endl; 

    //output
    /*
    Boost
    C
    +
    +
    libraries
    */
}

void version11() {
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer; 
    std::string s = "Boost C++ libraries"; 
    boost::char_separator<char> sep(" ", "+", boost::keep_empty_tokens); 
    tokenizer tok(s, sep); 
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) 
        std::cout << *it << std::endl; 

    //output
    /*
    Boost
    C
    +

    +

    libraries
    */
}

void version10() {
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer; 
    std::string s = "Boost C++ libraries"; 
    boost::char_separator<char> sep(" "); 
    tokenizer tok(s, sep); 
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) 
        std::cout << *it << std::endl;

    //output
    /*
    Boost
    C++
    libraries
    */
}
void version9() {
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer; 
    std::string s = "Boost C++ libraries"; 
    tokenizer tok(s); 
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) 
        std::cout << *it << std::endl; 

    //output
    /*
    Boost
    C
    +
    +
    libraries
    */
}

void version8() {
    std::string s = "Boris Schäling"; 
    std::vector<std::string> v; 
    boost::algorithm::split(v, s, boost::algorithm::is_space()); 
    std::cout << v.size() << std::endl; // 2
}


void version7() {
    std::string s = "Boris Schäling"; 
    std::cout << boost::algorithm::starts_with(s, "Boris") << std::endl; 
    std::cout << boost::algorithm::ends_with(s, "Schäling") << std::endl; 
    std::cout << boost::algorithm::contains(s, "is") << std::endl; 
    std::cout << boost::algorithm::lexicographical_compare(s, "Boris") << std::endl;

    //output
    /*
    1
    1
    1
    0
    */ 
}


void version6() {
    std::string s = "123456789Boris Schäling123456789"; 
    std::cout << "." << boost::algorithm::trim_left_copy_if(s, boost::algorithm::is_digit()) << "." << std::endl; 
    std::cout << "." <<boost::algorithm::trim_right_copy_if(s, boost::algorithm::is_digit()) << "." << std::endl; 
    std::cout << "." <<boost::algorithm::trim_copy_if(s, boost::algorithm::is_digit()) << "." << std::endl; 

    /*output:
    .Boris Schäling123456789.
    .123456789Boris Schäling.
    .Boris Schäling.
    *
}

void version5() {
    std::string s = "\t Boris Schäling \t"; 
    std::cout << "." << boost::algorithm::trim_left_copy(s) << "." << std::endl; 
    std::cout << "." <<boost::algorithm::trim_right_copy(s) << "." << std::endl; 
    std::cout << "." <<boost::algorithm::trim_copy(s) << "." << std::endl; 

    //output
    /*.Boris Schäling 	.
    .	 Boris Schäling.
    .Boris Schäling.
    */
}

void version4() {
    std::string s = "Boris Schäling"; 
    std::cout << boost::algorithm::replace_first_copy(s, "B", "D") << std::endl; 
    std::cout << boost::algorithm::replace_nth_copy(s, "B", 0, "D") << std::endl; 
    std::cout << boost::algorithm::replace_last_copy(s, "B", "D") << std::endl; 
    std::cout << boost::algorithm::replace_all_copy(s, "B", "D") << std::endl; 
    std::cout << boost::algorithm::replace_head_copy(s, 5, "Doris") << std::endl; 
    std::cout << boost::algorithm::replace_tail_copy(s, 8, "Becker") << std::endl;

    //output
    /*  Doris Schäling
        Doris Schäling
        Doris Schäling
        Doris Schäling
        Doris Schäling
        Boris SBecker
    */ 
}

void version3() {
    std::vector<std::string> v; 
    v.push_back("Boris"); 
    v.push_back("Schäling"); 
    std::cout << boost::algorithm::join(v, " ") << std::endl;   //Boris Schäling
}

void version2() {
  
    std::string s = "Boris Schäling"; 
    boost::iterator_range<std::string::iterator> r = boost::algorithm::find_first(s, "Boris"); 
    std::cout << r << std::endl;    // Boris
    r = boost::algorithm::find_first(s, "xyz"); 
    std::cout << r << std::endl;    //empty
}


void version1() {
    std::string s = "Boris Schäling"; 
    std::cout << boost::algorithm::to_upper_copy(s) << std::endl; 
    std::cout << boost::algorithm::erase_first_copy(s, "i") << std::endl; 
    std::cout << boost::algorithm::erase_nth_copy(s, "i", 0) << std::endl; 
    std::cout << boost::algorithm::erase_last_copy(s, "i") << std::endl; 
    std::cout << boost::algorithm::erase_all_copy(s, "i") << std::endl; 
    std::cout << boost::algorithm::erase_head_copy(s, 5) << std::endl; 
    std::cout << boost::algorithm::erase_tail_copy(s, 8) << std::endl; 

    //output
    /*
    BORIS SCHäLING
    Bors Schäling
    Bors Schäling
    Boris Schälng
    Bors Schälng
    Schäling
    Boris S
    */
}