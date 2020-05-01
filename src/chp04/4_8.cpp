#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;

void sec4_8(){
  cout << "Begin sec 4.8" << endl;
  unsigned char bits = 0233;
  cout << (bits << 8) << endl;

  unsigned int quiz1 = 0;

  cout << (1UL << 27) << endl; // only bit 27 is set
  quiz1|= (1UL << 27); // set bit 27 to 1 in quiz1
  bool status = quiz1 & (1UL << 27);
  static_assert(sizeof(int) >= 4, "INT must have at least 4 bytes");
  cout << "On this machine int has " << sizeof(int) << " B" << endl;
  assert(status == true);

  quiz1 &= ~(1UL << 27); // set bit 27 to 0
  status = quiz1 & (1UL << 27);
  assert(status == false);
  
}

void ex4_27(){
  cout << "ex 4.27" << endl;

  unsigned int ul1 = 3, ul2 = 7;
  assert((ul1 & ul2) == 3);
  assert((ul1 | ul2) == 7);
  assert((ul1 && ul2) == true);
  assert((ul1 || ul2) == true);
  

  cout << "End" << endl;
  
}

int main(){
  sec4_8();
  ex4_27();



}
