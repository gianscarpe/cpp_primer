#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

void sec4_1_2(){
  cout << "Begin sec 4.1.2" << endl;

  vector<int> vec(10, 0);
  vec[1] = 6;

  auto value1 = *vec.begin();
  auto value2 = *vec.begin() + 1;
  assert(value1 == 0);
  assert(value2 == 1);

  cout << "End sec 4.1.2" << endl;
    
}

void sec4_1_3(){
  cout << "Begin sec 4.1.3" << endl;

  int i = 0;
  cout << i << " " << ++i << endl; // Undefined, no order is guarantee
  
}


int main(){
  sec4_1_2();
  sec4_1_3();
  return 1;
}
