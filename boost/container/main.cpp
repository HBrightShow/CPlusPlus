#include<iostream>
#include<boost/array.hpp>
#include<string>
#include<algorithm>
#include<boost/unordered_set.hpp>
#include<boost/multi_index/member.hpp>
#include<boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>

#include <boost/multi_index/member.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp> 
#include <boost/multi_index/identity.hpp> 
#include <boost/multi_index/random_access_index.hpp> 
#include <boost/multi_index/mem_fun.hpp> 

#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp> 
#include <boost/bimap/unconstrained_set_of.hpp> 
#include <boost/bimap/support/lambda.hpp>



void version1();
void version2();
void version3();
void version4();
void version5();
void version6();
void version7();
void version8();

int main() {

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
void version8() {
    typedef boost::bimap<std::string, boost::bimaps::unconstrained_set_of<int>> bimap; 
  bimap persons; 

  persons.insert(bimap::value_type("Boris", 31)); 
  persons.insert(bimap::value_type("Anton", 31)); 
  persons.insert(bimap::value_type("Caesar", 25)); 

  bimap::left_map::iterator it = persons.left.find("Boris"); 
  persons.left.modify_key(it, boost::bimaps::_key = "Doris"); 

  std::cout << it->first << std::endl;  //Doris
}
void version7() {
    typedef boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::multiset_of<int>> bimap; 
  bimap persons; 

  persons.insert(bimap::value_type("Boris", 31)); 
  persons.insert(bimap::value_type("Anton", 31)); 
  persons.insert(bimap::value_type("Caesar", 25)); 

  std::cout << persons.left.count("Boris") << std::endl;    //1
  std::cout << persons.right.count(31) << std::endl;    //2

  for (bimap::iterator it = persons.begin(); it != persons.end(); ++it)  {
      std::cout << it->left << ":" << it->right << std::endl;
  }
  /*
    Anton:31
    Boris:31
    Caesar:25
  */
}
void version6() {
    typedef boost::bimap<std::string, int> bimap; 
    bimap persons; 

    persons.insert(bimap::value_type("Boris", 31)); 
    persons.insert(bimap::value_type("Anton", 31)); // this item invaild
    persons.insert(bimap::value_type("Caesar", 25)); 

    std::cout << persons.left.count("Boris") << std::endl; //1
    std::cout << persons.right.count(31) << std::endl;  //1

    for (bimap::iterator it = persons.begin(); it != persons.end(); ++it) 
        std::cout << it->left << ":" << it->right << std::endl;  //only output two item
    /*
    Boris:31
    Caesar:25
    */
    
}
class person5 
{ 
public: 
  person5(const std::string &n, int a) 
    : name(n), age(a) 
  { 
  } 

  bool operator<(const person5 &p) const 
  { 
    return age < p.age; 
  } 

  std::string get_name() const 
  { 
    return name; 
  } 

private: 
  std::string name; 
  int age; 
}; 

typedef boost::multi_index::multi_index_container< 
  person5, 
  boost::multi_index::indexed_by< 
    boost::multi_index::ordered_unique< 
      boost::multi_index::identity<person5> 
    >, 
    boost::multi_index::hashed_unique< 
      boost::multi_index::const_mem_fun< 
        person5, std::string, &person5::get_name 
      > 
    > 
  > 
> person5_multi;

void version5() {
    person5_multi persons5; 

  persons5.insert(person5("Boris", 31)); 
  persons5.insert(person5("Anton", 31)); 
  persons5.insert(person5("Caesar", 25)); 

  std::cout << persons5.begin()->get_name() << std::endl; //Caesar

  const person5_multi::nth_index<1>::type &hashed_index = persons5.get<1>(); 
  std::cout << hashed_index.count("Boris") << std::endl;    //1


}
struct person4 
{ 
  std::string name; 
  int age; 

  person4(const std::string &n, int a) 
    : name(n), age(a) 
  { 
  } 
}; 

typedef boost::multi_index::multi_index_container< 
  person4, 
  boost::multi_index::indexed_by< 
    boost::multi_index::sequenced<>, 
    boost::multi_index::ordered_non_unique< 
      boost::multi_index::member< 
        person4, int, &person4::age 
      > 
    >, 
    boost::multi_index::random_access<> 
  > 
> person4_multi;

void version4() {

    person4_multi persons4; 

  persons4.push_back(person4("Boris", 31)); 
  persons4.push_back(person4("Anton", 35)); 
  persons4.push_back(person4("Caesar", 25)); 

  const person4_multi::nth_index<1>::type &ordered_index = persons4.get<1>(); 
  person4_multi::nth_index<1>::type::iterator lower = ordered_index.lower_bound(30); 
  person4_multi::nth_index<1>::type::iterator upper = ordered_index.upper_bound(40); 

  for (; lower != upper; ++lower) 
    std::cout << lower->name << std::endl; //Boris  Anton

  const person4_multi::nth_index<2>::type &random_access_index = persons4.get<2>(); 
  std::cout << random_access_index[2].name << std::endl; //Caesar


}
struct person3 
{ 
  std::string name; 
  int age; 

  person3(const std::string &n, int a) 
    : name(n), age(a) 
  { 
  } 
}; 

typedef boost::multi_index::multi_index_container< 
  person3, 
  boost::multi_index::indexed_by< 
    boost::multi_index::hashed_non_unique< 
      boost::multi_index::member< 
        person3, std::string, &person3::name 
      > 
    >, 
    boost::multi_index::hashed_non_unique<  //hashed_unique
      boost::multi_index::member< 
        person3, int, &person3::age 
      > 
    > 
  > 
> person3_multi;


void version3() {
    person3_multi persons3; 

    persons3.insert(person3("Hml", 25)); 
    persons3.insert(person3("Boris", 31)); 
    persons3.insert(person3("Anton", 35)); 
    persons3.insert(person3("Caesar", 25)); 

    std::cout << persons3.count("Boris") << std::endl; //1

    const person3_multi::nth_index<1>::type &age_index = persons3.get<1>(); 
    std::cout << age_index.count(25) << std::endl; //2

    person3_multi::iterator it = persons3.find("Boris");
    persons3.modify(it,[&]( person3& p) {
        p.age = 32;
    });

    const person3_multi::nth_index<1>::type &age2_index = persons3.get<1>();
    std::cout << age2_index.count(32) << std::endl;     // 1
}

struct person {
    std::string name;
    int age;

    person(const std::string &n, int a)
    :name(n),age(a) {
    }

    bool operator==(const person &p) const {
        return name == p.name && age == p.age;
    }
};
//need this function by struct person
std::size_t hash_value(person const &p) {
    std::size_t seed = 0;
    boost::hash_combine(seed, p.name);
    boost::hash_combine(seed, p.age);
    return seed;
}

void version2() {
    typedef boost::unordered_set<person> unordered_set;
    unordered_set set;
    set.insert(person("Boris",31));
    set.insert(person("Anton",35));
    set.insert(person("Caesar",25));


}

void version1() {

    typedef boost::array<std::string, 3> array;
    array a;
/*
    a[0] = "Boris";
    a.at(1) = "Anton";
    *a.rbegin() = "Caesar";
*/
    a = { "Boris", "Anton", "Caesar" };
    std::sort(a.begin(), a.end());
    for(array::const_iterator it = a.begin(); it != a.end(); ++ it) {
        std::cout << *it << std::endl;
    }

    std::cout << a.size() << std::endl;
    std::cout << a.max_size() << std::endl;
}