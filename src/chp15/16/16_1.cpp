#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Blob.hpp"

using std::cout; using std::endl; using std::vector; using std::string;
using std::list;

// Templates
template <typename T>
int compare(const T &v1, const T &v2) {
  if (v1 < v2)
    return -1;
  if (v2 < v1)
    return +1;
  return 0;
}

template <typename T, typename V>
bool myfind(const T &begin, const T &end, V value){
  for(T it = begin; it != end; ++it)
    if (*it == value)
      return true;
  return false;
}

// IF we want to compare const char[N] vectors (namely, string literals), we
// need to know at COMPILE TIME the length of each vector. SOLUTION: use
// template constat expression
template<int N, int M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
  return strcmp(p1, p2);
}

void sec16_1_1(){

  cout << compare(1, 0) << endl;
  cout << compare(1.4, 0.3) << endl;
  cout << compare(vector<int>(10, 10), vector<int>(4, 4)) << endl;
  cout << compare(string("ciao"), string("hello")) << endl;
  //  compare string literals like this
  //  cout << compare("ciao", "hello") << endl; impossible for literal of
  //  different lengths, because T=char[4] or char[5]
  cout << (string("ciao") < string("hello")) << endl;

}

void ex16_4(){
  vector<int> v { 1, 2, 3, 4 };
  list<string> l{"adfa", "casdf", "aaa", "a"};
  cout << "FIND:" << myfind(v.begin(), v.end(), 4) << endl;
  cout << "FIND:" << myfind(v.begin(), v.end(), 7) << endl;
  cout << "FIND:" << myfind(l.begin(), l.end(), "a") << endl;
}

template <typename T, unsigned N>
T* mybegin(T (&v)[N]){
  return v;
}

template <typename T, unsigned N>
T* myend(T (&v)[N]){
  return v + N;
}

void ex16_6(){
  int v[5] = {1, 2, 3, 4, 5};
  cout << "FIND:" << myfind(mybegin(v), myend(v), 3) << endl;
  cout << "FIND:" << myfind(mybegin(v), myend(v), 7) << endl;
}

template<typename T, unsigned N>
constexpr unsigned size(const T (&v)[N]){
  return N;
}

void ex16_7(){
  int v[5] = {1, 2, 3, 4, 5};
  cout << "SIZE:" << size(v) << endl;
  int p[size(v)]; // constexpr as size of an array
}

int main(){
  sec16_1_1();
  ex16_4();
  ex16_6();
  ex16_7();
}
