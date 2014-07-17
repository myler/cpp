#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "boost/any.hpp"

class A {
public:
  void some_function() { std::cout << "A::some_function()\n"; }
};

class B {
public:
  void some_function() { std::cout << "B::some_function()\n"; }
};

class C {
public:
  void some_function() { std::cout << "C::some_function()\n"; }
};

int main() {
  std::cout << "Example of using any.\n\n";

  std::vector<boost::any> store_anything;

  store_anything.push_back(A());
  store_anything.push_back(B());
  store_anything.push_back(C());

  store_anything.push_back(std::string("This is fantastic! "));
  store_anything.push_back(3);
  store_anything.push_back(std::make_pair(true, 7.92));

  void print_any(boost::any& a);

  std::for_each(
  store_anything.begin(),
  store_anything.end(),
  print_any);
}

void print_any(boost::any& a) {
  if (A* pA=boost::any_cast<A>(&a)) {
    pA->some_function();
  }
  else if (B* pB=boost::any_cast<B>(&a)) {
    pB->some_function();
  }
  else if (C* pC=boost::any_cast<C>(&a)) {
    pC->some_function();
  } else {
    try {
      std::cout << boost::any_cast<std::string>(a) << '\n';
    }
    catch(boost::bad_any_cast&) {
      std::cout << "Oops!\n";
    }
  }
}