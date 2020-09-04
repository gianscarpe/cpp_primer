#include <utility>
#include "Quote.hpp"
#include <vector>
#include <iostream>
#include "Basket.hpp"

using std::vector; using std::shared_ptr; using std::make_shared;
using std::cout; using std::endl;


class Base{
public:
  
  //  Base() = default;
  Base(const Base &b) { mem = b.mem; }
  virtual ~Base();
private:
  int mem;
  
};

class D: public Base{
public:
  D(const D &d) : Base(d) {value = d.value;}; // IF not specified, use base
					      // constuctor
  // ERROR: Base doesn't have default constructor  D(const D &d)  {value = d.value;}; // IF not specified, use base constuctor
  D(D &&d) : Base(std::move(d)) { value = d.value; };
  ~D() {
    // clean up
  }
    
  D& operator=(const D& rhs){
    Base::operator=(rhs); //assign base part to this
    value = rhs.value;
    return *this;
  }
  
private:
  int value;
  
};


void ex15_26(){
  Quote q1, q2;
  q2 = q1;
  q2 = std::move(q1);

  Bulk_quote b1, b2;
  b2 = b1;
  b2 = std::move(b1);
}

void ex15_28(){
  cout << "Ex 15.28" << endl;
  vector<Quote> v;
  Bulk_quote b("aa", 50, 10, .25);
  v.push_back(b);

  cout << v[0].net_price(20) << endl;
  vector<Quote*> v1;
  Bulk_quote* b1 = new Bulk_quote("aa", 50, 10, .25);
  v1.push_back(b1);
  
}


void sec15_7_4(){
  Basket bsk;
  bsk.add_item(make_shared<Quote>("aaa", 45));
  bsk.add_item(make_shared<Bulk_quote>("bbb", 45, 3., .15));

  
}

int main(){
  ex15_26();
  ex15_28();
}
