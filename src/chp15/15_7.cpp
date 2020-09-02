#include <utility>
#include "Quote.hpp"

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

int main(){
  ex15_26();
}
