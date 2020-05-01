#include <iostream>

void ex2_5_1() { // alias exercise
  
  typedef double wages; // double
  typedef wages *p; // pointer to double

  // const + typdef: strange!

  wages myWage = 42.00;
  const p constPointerToDouble = &myWage; // pointer is constant, value not!
  *constPointerToDouble = 31.0;

  assert(myWage == 31);

  const p *pointerToConstPointerToDouble = &constPointerToDouble; // value, which is a pointer, is constant!
  // Readonly: cannot do   *pointerToConstPointerToDouble = &myWage;
  **pointerToConstPointerToDouble = 43; // value is not!
  
  assert(myWage == 43);

  std::cout << "Everthing is right!" << std::endl;
  
}

void ex2_5_2() {

  int myValue = 42;
  const int *pointerToConst = &myValue;

  auto automaticPointer = pointerToConst;

  // Compiler error: *automaticPointer = 32; // Readonly

   
}

void ex2_5_3(){
  std::cout << "BEGIN - EX 2.5.3" << std::endl;
  int x = 1;
  decltype(x++) y = 4; // It's not evaluated!
  assert(x == 1);
  assert(y == 4);

  int value = 42;
  int &refToValue = value;

  // (value) is an expression -> its type is a reference
  decltype((value)) anotherRefToValue = value;

  assert(anotherRefToValue == 42);

  int a = 3, b = 4;

  decltype(a) c = a;
  decltype((b)) d =a;
  decltype(a = b) e = a;
  
  ++c;
  ++d;
  ++e;

  assert(a == 5); // int
  assert(b == 4); // int
  assert(c == 4); // int
  assert(d == 5); // int&
  assert(e == 5);
  
  std::cout << "ALL PASSED! END - EX 2.5.3" << std::endl;
  
    
}

int main(){

  ex2_5_1();
  ex2_5_2();
  ex2_5_3();

  return 1;
}
