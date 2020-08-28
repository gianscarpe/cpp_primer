#include "Sales_data.hpp"
#include "String.hpp"
#include <string>
#include <iostream>
#include <fstream>
using std::string; using std::ifstream; using std::ofstream;
using std::cout; using std::endl;


void sec14_1(){
  ifstream input("input.txt");
  ofstream out("out.txt", ofstream::app);
  
  Sales_data data1, data2;
  input >> data1 >> data2;

  cout << data1;
  cout << data2;
  Sales_data sum;
  if (data1.isbn() == data2.isbn()){
    sum = data1 + data2;
    out << data1 + data2 << endl;
    cout << sum << endl;
  
  } else {
    std::cout << "Cannot sum transactions with different bookNo! First: "
              << data1.isbn() << " second: " << data2.isbn() << std::endl;
  }
}

void ex14_16(){
  String s1("hi"), s2("hi");
  cout << s1 << " " << s2 << endl;
  assert(s1 == s2);
}

int main(){
  sec14_1();
  ex14_16();
}
