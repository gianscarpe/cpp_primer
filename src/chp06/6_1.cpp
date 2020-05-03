#include <iostream>
#include <vector>
#include "Chapter6.h"
using std::cin; using std::cout; using std::endl;

int fact(int n){
  long result = 1;
  while (n > 1)
    result *= n--;
  return result;
}


int abs(int value){
  return (value > 0) ? value : -value;
}

size_t count(){
  static size_t count = 0;
  return ++count;
  
}

void sec6_1(){
  cout << "Begin sec 6.1" << endl;
  assert(fact(3) == 6);
  assert(count() == 1);
  assert(count() == 2);
  
}



int main(){

  sec6_1();
  return 1;
}
