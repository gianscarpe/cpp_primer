#include <iostream>

std::istream &func(std::istream &is){

  char c;
  while (is >> c){
    std::cout << c << std::endl;
  }

  is.clear();
  return is;
}

void ex8_1(){
  std::istream &is = std::cin;
  std::istream &f = func(is);
  assert(f.good());
}


int main(){
  ex8_1();
  
  return 1;
}
