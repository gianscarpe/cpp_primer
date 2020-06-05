#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <initializer_list>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector;

typedef string::size_type sz;
string screen(sz, sz, char = '#'); // default arguments
/*
  string screen(sz, sz, char = '#'); // multi delcaration error!
 */

string screen(sz ht = 10, sz wid = 80, char bg){
  string result = "";
  for (sz r = 0; r != ht; ++r) {
    for (sz c = 0; c != wid; ++c){
      result += bg;
    }
    result = result + '\n';
  
  }
  #ifndef NDEBUG
  cerr << __func__ << result << endl;
  #endif
  
  return result;
  
}


string screen2(sz ht = 10, sz wid = 80, string bg="#"){
  string result = "";
  for (sz r = 0; r != ht; ++r) {
    for (sz c = 0; c != wid; ++c){
      result += bg;
    }
    result = result + '\n';
  
  }
  
  return result;
  
}



void sec6_5_1(){
  cout << "Begin sec 6.5.1" << endl;
  cout << screen() << endl;
  cout << screen('$') << endl; // wired!
  // to override bg, you must follow the order
  cout << screen(10, 80, '$');
  //cout << screen2("$"); // error! you must follow the order of arguments!
}


inline const string &shorter(const string &s1, const string &s2){
  return (s1.size() < s2.size()) ? s1 :s2;
}

void sec6_5_2(){
  cout << "Begin sec 6.5.2" << endl;
  // inline function are replaced inline
  cout << shorter("hi", "hello");
  assert(shorter("hi", "hello") == "hi"); 
}


constexpr string *isShort(string *s1, string *s2){
  return (s1->size() < s2->size()) ? s1 :s2;
}

void ex6_46(){

  
  // constexpr string s = isShort("hi", "hello"); error
  string s1 = "hi";
  string s2 = "hello";
  //constexpr string s = isShort(&s1, &s2);
  
}



int main(){
  sec6_5_1();
  sec6_5_2();
}
