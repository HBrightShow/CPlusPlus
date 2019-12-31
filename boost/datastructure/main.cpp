#include<iostream>
#include<boost/tuple/tuple.hpp>
#include<boost/tuple/tuple_io.hpp>

#include<boost/any.hpp>
#include<typeinfo>
#include<vector>

void version1();
void version2();
void version3();
void version4();
void version5();
void version6();

int main() {

    //version1();
    //version2();
    //version3();
    //version4();
    //version5();
    version6();
    


    return 0;
}
void version6() {
    boost::any  a = "hml";
    if(!a.empty()) {
        const std::type_info& ti = a.type();
        std::cout << ti.name() << std::endl;  // PKc
    }

    std::vector<boost::any> vc;
    vc.push_back("hml");
    vc.push_back(100);

    std::string sam = "date";
    const char* name = typeid(sam).name();
    std::cout << name << std::endl;     //NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
}

boost::tuple<std::string, int> func() {
    return boost::make_tuple("Error message", 2009);
}

void version5() {
    std::string errmsg;
    int errcode;
    boost::tie(errmsg, errcode) = func();
    std::cout << errmsg << errcode << std::endl;        //Error message2009
}
void version4() {
    typedef boost::tuple<std::string&, std::string&, int> person; 

    std::string firstname = "Boris"; 
    std::string surname = "Schaeling"; 
    int shoesize = 43; 
    person p = boost::make_tuple(boost::ref(firstname), boost::ref(surname), shoesize); 
    surname = "Becker"; 
    std::cout << p << std::endl;   //(Boris Becker 43)


}
void version3() {
    typedef boost::tuple<std::string&, std::string&, int&> person;
    std::string firstname = "Boris"; 
    std::string surname = "Schaeling"; 
    int shoesize = 43; 
    person p = boost::tie(firstname, surname, shoesize); 
    surname = "Becker"; 
    std::cout << p << std::endl;    //(Boris Becker 43)
}
void version2() {
    int sam = 100;
    std::cout << &sam << std::endl;     //0x7fff0536e778

    int &a = sam;
    std::cout << &a << std::endl;       //0x7fff0536e778
    typedef boost::tuple<int, std::string, int> person;
    

    person cp = boost::make_tuple(boost::ref(sam), "Schaeling", 43);
    //person cp = boost::make_tuple(sam, "Schaeling", 43);

    sam = 500;
    std::cout << &cp.get<0>() << std::endl; //0x7fff0536e7d0

    std::cout << cp << std::endl;   //(100 Schaeling 43)

    cp.get<0>() = 200;
    std::cout << &cp.get<0>() << std::endl;     //0x7fff0536e7d0
    std::cout << sam << std::endl;      // 500
    std::cout << cp << std::endl;       // (200 Schaeling 43)

    sam = 300;
    std::cout << cp << std::endl;   //(200 Schaeling 43)
}

void version1() {
    typedef boost::tuple<std::string, std::string, int> person;
    person p("hml", "bright", 100);
    std::cout << p << std::endl;   // (hml bright 100)

    std::cout << boost::make_tuple("Boris", "Schaeling", 43) << std::endl; //(Boris Schaeling 43)

    std::string sam= "sam";
    std::cout << &sam << std::endl;     //0x7ffddb4f7a80
    //person cp = boost::make_tuple(boost::ref(sam), "Schaeling", 43);
    person cp = boost::make_tuple(sam, "Schaeling", 43);

    std::cout << cp.get<0>() << std::endl;      //sam
    std::cout << boost::get<0>(cp) << std::endl;  //sam

    cp.get<1>() = "Becker";
    std::cout << cp << std::endl;           //(sam Becker 43)

    cp.get<0>() = "date";
    std::cout << &cp.get<0>() << std::endl;     //0x7ffddb4f7af0
    std::cout << sam << std::endl;      // sam
    std::cout << cp << std::endl;       // (date Becker 43)
}