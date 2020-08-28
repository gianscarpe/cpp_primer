#include "PrintString.hpp"
#include "ReadString.hpp"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using std::vector; using std::string; using std::cout; using std::endl;

void sec14_8(){
  PrintString p('\n');  
  p("ciao");
  vector<string> v = {"ciao", "come", "va"};
  std::for_each(v.cbegin(), v.cend(), PrintString('\n'));
}

void ex14_35(){
  ReadString r("input.txt");
  PrintString p('\n');  
  p(r());
  

}

void ex14_36(){
  vector<string> v;
  cout << "Reading" << endl;
  ReadString r("input.txt");
  string s;
  while ((s = r())!="")
    v.push_back(s);

  cout << v.size() << endl;
  std::for_each(v.cbegin(), v.cend(), PrintString('\n'));
}

int main(){
  sec14_8();
  //ex14_35();
  ex14_36();
}
