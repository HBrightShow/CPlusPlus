#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

void version1();
void version2();
void version3();
void version4();
void version5();
void version6();
void version7();

int main()
{

    //version1();
    //version2();
    //version3();
    //version4();
    //version5();
    //version6();
    version7();

    return 0;
}

void version7() {
    boost::gregorian::date d(2009, 1, 5); 
  boost::gregorian::day_iterator it(d); 
  std::cout << *++it << std::endl;  //2009-Jan-06
  std::cout << boost::date_time::next_weekday(*it, boost::gregorian::greg_weekday(boost::date_time::Friday)) << std::endl; //2009-Jan-09
}
void version6() {
    boost::gregorian::date d1(2009, 1, 30); 
    boost::gregorian::date d2(2009, 10, 31); 
    boost::gregorian::date_period dp(d1, d2); 
    std::cout << dp.contains(d1) << std::endl; // 1
    std::cout << dp.contains(d2) << std::endl;  // 0
}
void version5() {
    boost::gregorian::date d1(2009, 1, 30); 
    boost::gregorian::date d2(2009, 10, 31); 
    boost::gregorian::date_period dp(d1, d2); 
    boost::gregorian::date_duration dd = dp.length(); //274
    std::cout << dd.days() << std::endl;
}

//controlled by  BOOST_DATE_TIME_OPTIONAL_GREGORIAN_TYPES  
void version4() {
    boost::gregorian::date d(2009, 1, 30); 
    boost::gregorian::months ms(1); 
    boost::gregorian::date d2 = d + ms; 
    std::cout << d2 << std::endl; //2009-Feb-28
    boost::gregorian::date d3 = d2 - ms; 
    std::cout << d3 << std::endl; //2009-Jan-31
}

void version3() {
    boost::gregorian::date d(2009, 1, 31); 
    boost::gregorian::months ms(1); 
    boost::gregorian::date d2 = d + ms; 
    std::cout << d2 << std::endl; //2009-Feb-28
    boost::gregorian::date d3 = d2 - ms; 
    std::cout << d3 << std::endl; //2009-Jan-31
}


void version2() {
    boost::gregorian::date_duration dd(4);
    std::cout << dd.days() << std::endl;        //  4

    boost::gregorian::weeks ws(4);
    std::cout << ws.days() << std::endl;        //28

    boost::gregorian::months ms(4);
    std::cout << ms.number_of_months() << std::endl;        //4

    boost::gregorian::years ys(4);
    std::cout << ys.number_of_years() << std::endl;     //4
}

void version1()
{
    boost::gregorian::date d(2019, 12, 8);
    std::cout << d.day() << std::endl;
    std::cout << d.month() << std::endl;
    std::cout << d.year() << std::endl;
    std::cout << d.day_of_week() << std::endl;
    std::cout << d.end_of_month() << std::endl;
    /*
    8
    Dec
    2019
    Sun
    2019-Dec-31

    */

   boost::gregorian::date d1(2019, 12, 8);
   boost::gregorian::date d2(2019, 12, 2);
   boost::gregorian::date_duration dd = d1 - d2;
   std::cout << dd.days() << std::endl;     //  6


   
}