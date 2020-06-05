#include "Screen.hpp"
#include <iostream>

int main(){
  Window_mgr manager;
  Screen s1 = Screen(24, 10, '%');
  s1.display(std::cout);
   s1.move(3, 2).set('$').display(std::cout);
}
