#include "Sales_data.hpp"
#include <vector>
using std::vector;

struct X { 
  X (int i, int j): base(i), rem(base % j) { } 
  int base, rem; 
};


struct NoDefault{
  int x;
  NoDefault(int j) : x(j) {};
};


struct C{
  NoDefault b;
  C(NoDefault j) : b(j) {};
  C() : C(0) {};
};

class Default{
public:
  constexpr Default(bool b = true) : Default(b, b, b) {}
  constexpr Default(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
  constexpr bool any() const {return hw || io || other;}
  void set_io(bool b) {io = b;}
  void set_hw(bool b) { hw = b; }
  void set_other(bool b) { other = b;}

private:
  bool hw;
  bool io;
  bool other;
}; // Literal class with constexpr constructor
  
void ex_7_5(){
  C test;
  vector<NoDefault> v; // no problem
  // Error: no default  vector<NoDefault> v(10);
  vector<NoDefault> v2(10, 42);
  vector<C> c(10); // no problem
  
}

int main(){
  Sales_data first;
  ex_7_5();
  constexpr Default f(true);
  return 1;
}
