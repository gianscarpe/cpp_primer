#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <initializer_list>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector;

void f(){
  cout << "No params" << endl;
}

void f(int i1, int i2){
  cout << "int int" << endl;
}

void f(int i1){
  cout << "int" << endl;
}

// Remember: every conversion is the same.

/* A function like this would become
   ambiguous with f(double, double=default) 

void f(double d){
  
}
*/
void f(double d1, double d2=32.23){
  cout << "double double" << endl;
  
}

void ex6_51(){
  f();
  f(42.42);
  f(3);
  f(3, 34);
  // f(3.2, 4); ambigous
  
}

int calc(char*, char*);
int calc(char* const, char* const);
int calc(const char*, const char*);

int main(){
  ex6_51();
  return 1;
}
