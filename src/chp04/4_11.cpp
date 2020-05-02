#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

void sec4_11_3(){
  // Explicit cast
  cout << "Begin sec 4.11.3" << endl;
  double slope = static_cast<int>(4.3F) / 2;
  cout << "result: " << slope << endl;
  cout << typeid(slope).name() << endl;

  // pointers

  void* pt = &slope;
  cout << "Retrieve value from pointer: " << *static_cast<double*>(pt) << endl;

  // Note: undefined
  cout << "Retrieve value from pointer (erroneous type): " <<
    *static_cast<float*>(pt) << endl;

  // Const and non-const
  
  const double value = 41;
  
  /* Compile error: cannot cast nonconst to const
     double *ptr = &value;
  */

  double* non_const_ptr = const_cast<double*>(&value);
  // Note: writing through non_const_ptr is UNDEFINED if the value pointed is CONST
  *non_const_ptr = 2.0;
  cout << "What's the value now? " << *non_const_ptr << endl;

  // reinterpreting the bits
  int *ip;
  char *pc = reinterpret_cast<char*>(ip);
  string str(pc);
  cout << "Bizare run-time behaviour: " << str << endl;
    
}

void ex4_36(){
  cout << "Begin ex 4.36" << endl;
  int i = 42;
  double d = 2.534;
  i *= static_cast<int>(d);
  cout << "result:" << i << endl;
  assert(i == 84);

}

int main(){
  sec4_11_3();
  ex4_36();
  

  return 1;
}
