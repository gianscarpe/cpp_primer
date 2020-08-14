#include <utility>
#include <vector>
#include <iostream>
#include "String.hpp"

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

int main(){
  ex13_46();
  ex13_44();
}
