#include <string>

struct SmallInt;

struct LongDouble{
  LongDouble operator+(const SmallInt&);
  LongDouble(double = 0.0);
  operator double();
  operator float();
};


class SmallInt { 
  friend 
  SmallInt operator+(const SmallInt&, const SmallInt&);
public:
  SmallInt(int = 0);
  operator int() const { return val; } // conversion to  int
private:
  std::size_t val; 
};

void ex14_50(){
  LongDouble ldj;
  // ERROR: ambiguous int ex1 = ldj;
  float ex2 = ldj;
}


void ex14_51(){
  void calc(int);
  void calc(LongDouble);
  double dval;
  calc(dval);
}

void ex14_52(){
  LongDouble operator+(LongDouble&, double);
  SmallInt s;
  LongDouble d;
  d = d + s; // operator+(SmallInt)
  // Error: ambiguous  d = s + d; 
}

void ex14_53(){
  SmallInt s1(3);
  double d = s1 + SmallInt(3.4);
  
}
