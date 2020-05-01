#include <iostream>
#include "const_file.h"

extern const int magicNumber;

void ex2_4(){
  const int bufSize = 42;

  std::cout << "My magic number: " << magicNumber << std::endl;

}

void ex2_4_2(){
  const int  *pointerToMagic;
  pointerToMagic = &magicNumber;
  std::cout << "Pointer to magic number: " << *pointerToMagic << std::endl;

  int magic = 5;
  const int *pointerToBelievedConst = &magic;
  int const *pointer = pointerToMagic;

  //  Unlike references, pointers are objects
  int *const constPointerToInt = &magic;
  *constPointerToInt = 3;

  std::cout << "Number modiifed by constPointer: " << magic << std::endl;

  // Const pointer to believed const
  const int *const constPointerToBelievedConst = pointerToMagic;
  // Error: constPointerToBelievedConst = &magic;`
  // Error: *constPointerToBelievedConst = 3;

}

int nullOutsideFunction = 0;
void ex2_4_4(){
  std::cout <<"Test" << std::endl;
  constexpr int *p = nullptr; // constant pointer

  int* const j  = p; // constant pointer
  const int *q = nullptr; // pointer to const



  // int null = 0;
  // *p = null;
  // // Error: segmentation fault

  // // Legit; the pointer points to the same address, for constexpr it must be
  // static,the value can be modified
  constexpr int *z = &nullOutsideFunction;
  *z = 42;

  std::cout << "Number pointed is modifed: " << *z << std::endl;

}

int main(){
  ex2_4();
  ex2_4_2();
  ex2_4_4();

}
