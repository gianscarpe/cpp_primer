#include "Quote.hpp"

class Base {
public:
  int pub_mem;

protected:
  int prot_mem;

private:
  int priv_mem;
 
};

struct Pub_Derv: Base{
  int f() { return prot_mem; }
  void memf(Base &b) { b = *this; }
};

struct Priv_Derv: private Base{
  int f1() const { return prot_mem; }
  void memf(Base &b) { b = *this; }
};

struct Prot_Derv: protected Base{
  int f1() const { return prot_mem; }
  void memf(Base &b) { b = *this; }
};


struct Derived_from_Pub : public Pub_Derv {
  int use_base() { return prot_mem; }
  void memf(Base &b) { b = *this; }
  
};


struct Derived_from_Prot : public Prot_Derv {
  int use_base() { return prot_mem; }
  void memf(Base &b) { b = *this; }
  
};


struct Derived_from_Priv : public Priv_Derv {
  //  int use_base() { return prot_mem; }
  // ERROR:  void memf(Base &b) { b = *this; }
};




void ex15_17(){
  // abstract class:  Disc_quote q;
  Bulk_quote q("ciao", 4.3, 2, .5);
}

void ex15_19(){
  Pub_Derv d1;
  Priv_Derv d2;
  Prot_Derv d3;
  Derived_from_Pub d4;
  Derived_from_Prot d5;
  Derived_from_Priv d6;

  Base* p = &d1; 
  // ERROR  p = &d2;
  // ERROR p = &d3;
  p = &d4;
  // ERROR p = &d5;
  // ERROR p = &d6;
  
  
}

int main(){
  ex15_17();
  ex15_19();
}
