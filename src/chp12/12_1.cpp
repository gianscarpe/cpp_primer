#include <vector>
#include <iostream>
#include <memory>
#include "blob.hpp"

using std::make_shared; using std::unique_ptr;
using std::shared_ptr;
using std::vector; using std::cin; using std::cout; using std::endl;

void sec12_1(){
  shared_ptr<vector<int>> p = make_shared<vector<int>>(12, 42);
  auto second_p(p);

  for(auto c : *p){
    cout << c << " ";
  }
  cout << endl;
}

void sec12_1_1(){
  StrBlob s1;
  StrBlob s2({
	      "ciao", "come", "va"});
  StrBlob s3(s2);
  cout << s3.front() << " " << s3.back() << endl;
  const StrBlob s4(s3);
  cout << s4.front() << " " << s4.back() << endl;
  s2.push_back("about");
  cout << s4.size() << endl;
}

void sec12_1_2(){
  int *p1 = new int(10);
  // Const pointer TO const object of type int
  const int* const p2 = new int(42);
  // ERROR: *p2 = 41;
  // ERROR p2 = p1;
  
  cout << *p1 << endl;
  assert(*p1 == 10);

  delete p1;
  
}

vector<int>* allocate(){
  return new vector<int>();
}
vector<int>* read(vector<int>* v){
  int value;
  while(cin >> value)
    v->push_back(value);
  return v;
}
void print_vector(vector<int>* v){
  for(int value : *v)
    cout << value << " ";
  cout << endl;
  delete v;
}

void ex12_6(){
  print_vector(read(allocate()));
}

void process(shared_ptr<int> p) {
  cout << "Number of shared pointers: " << p.use_count() << endl;
  (*p)++;
}

void ex12_10(){
  shared_ptr<int> p(new int(42));
  //    process(shared_ptr<int>(p)); // should be 3!
  process(p);
  //process(shared_ptr<int>(p.get())); // should be 3!
  cout << "original: " << *p << endl;
}
void ex12_16(){
  unique_ptr<int> i(new int(42));
  // ERROR  unique_ptr<int> ip(i);

}
void ex12_17(){
  int ix = 42;
  int *pi = &ix;
  int *p2 = new int(233);
  // ERROR unique_ptr<int> p0(42);
  unique_ptr<int> p1(p2);
  cout << *p1 << endl;
  delete p2;
  cout << *p1 << endl;
  cout << "END" << endl;
}

int main(){
  sec12_1();
  sec12_1_1();
  sec12_1_2();
  //  ex12_6();
  ex12_10();
  ex12_16();
  ex12_17();
  return 1;
}
