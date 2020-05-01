#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;


void ex4_29(){
  cout << "Begine x 4.29" << endl;

  int x[10];
  int *p = x;
  cout << sizeof(x) / sizeof(*x) << endl; //10
  cout << sizeof(p) / sizeof(*p) << endl; // dim of pointer / dim of int

  int *v;
  assert(sizeof(v) / sizeof(int) == sizeof(p) / sizeof(*p) );
  
}

void sec4_9(){
  vector<int> v;
  vector<int> *p;
  cout << "Sizeof v: " << sizeof v << endl;
  cout << "Sizeof pointer to v: " << sizeof *p << endl;

  // Determine the number of elements of an array
  int arr[] =
  { 1,
    2,
    3,
    4 };

  size_t dim = sizeof(arr);
  cout << "N of elements: " << dim / sizeof(int) << endl;
  assert(dim/sizeof(int) == 4);
  
}
int main(){
  sec4_9();
  ex4_29();
  return 1;
}
