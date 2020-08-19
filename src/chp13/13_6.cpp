#include <utility>
#include <vector>
#include <iostream>
#include "String.hpp"
#include "HasPtr.hpp"

using std::vector; using std::cin; using std::endl; using std::cout;

int f(){
  return 42;
}
void ex13_46(){
  
  vector<int> v(10, 10);
  int&& r1 = f();
  int& r2 = v[0];
  int& r3 = r1;
  int&& r4 = v[0] * f();

  // Can use std::move to get rvalue reference from lvalue
  int&& r5 = std::move(v[0]);
  cout << r5 << endl;
  cout << v[0] << endl;
}

void ex13_44(){
  String s1("hi");
  print(s1);
  cout << "OK" << endl;
  String s3;
  s3 = s1;
  print(s3);
  cout << "INIT" << endl;
  vector<String> v;
  v.push_back("HELLO");
  v.push_back("HELLO");
  v.push_back("HELLO");
  cout << "END" << endl;
}

void ex13_52(){
  cout << "Ex 13.52" << endl;
  HasPtr hp1("ciao"), hp2("hi");
  hp1 = hp2;
  print(hp1);
  print(hp2);
  
  hp1 = std::move(hp2);
  cout << "END move" << endl;
  print(hp1);  
}

int main(){
  ex13_46();
  ex13_44();
  ex13_52();
}
