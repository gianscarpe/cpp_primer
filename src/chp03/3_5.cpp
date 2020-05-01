#include <iostream>
#include <vector>
#include <iterator>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

void sec3_5_1(){
  cout << "Begin ex 3.5.1" << endl;
  unsigned cnt;
  cnt = 42;
  constexpr unsigned sz = 42; // constant expression

  // Default initialization is not present!
  int v1[10];
  int v2[sz];
  std::string v3[cnt];
  int v4[] = {1, 3, 4, 6, 3};

  const unsigned alternative_size = 2;

  int v5[alternative_size] = {4, 2};

  char c1[] = "Hello"; // terminate with \0
  char c2[] = {'C', '+', '+'}; // no \0

  /* Compile error: no space for \0!
     const char c3[3] = "C++"; // no \0
     char c3[3] = "C++"; // no \0  
  */

  /* Compile error: cannot initialize by copy
     char c3[] = c1;
  */

  
  int *ptr1[10]; // array of pointers to int
  int (*ptr2)[10]; // pointer to array of ten ints

  
  // Note the difference!
  int tmp = 42;
  int tmparray[10] = {};
  (ptr1[1]) = &tmp;
  ptr2 = &tmparray;
  int (&ptr3)[10] = *ptr2;
  
  /* Compile error!
     (*ptr2) = tmparray;
  */

  tmparray[1] = 42;
  
  assert(c1[5] == '\0');
  assert(ptr3[1] == (*ptr2)[1]);

  cout << "End ex 3.5.1" << endl;
}

int text_size(){
  return 5;
}

void ex3_27(){
  cout << "Begin ex 3.27" << endl;
  unsigned buf = 1024;
 
  int v1[text_size()];
  int v2[buf];
  
  cout << "End ex 3.27" << endl;
}

int ia[10];
std::string sa[10];
void ex3_29(){
  cout << "Begin ex 3.29" << endl;

  int ia1[10];
  std::string sa1[10];

  assert(ia[0] == 0);
  assert(sa[0] == "");
  assert(sa1[0] == "");
  cout << "Undefined ia1[0]: " << ia1[0] << endl;
  assert(ia1[0] != 0);

  cout << "End ex 3.29" << endl;
  
}

void ex3_31(){
  cout << "Begin ex 3.31" << endl;
  constexpr size_t sz = 10;
  int v[sz] = {};
  
  for(int i = 0; i < sz; i++)
    v[i] = i;

  for (auto i : v)
    cout << i << " ";
  cout << "end ex 3.31" << endl;
}

void ex3_32(){
  cout << "Begin ex 3.32" << endl;

  constexpr size_t sz = 10;
  int v[sz] = {};
  
  for(int i = 0; i < sz; i++)
    v[i] = i;

  int vcopy[sz] = {};
  // Copy
  for(size_t i = 0; i < sz; i++)
    vcopy[i] = v[i];

  // With vector:

  std::vector<int> v3 { 10, 0 };
  for(int i = 0; i < 10; i++)
    v3[i] = i;

  std::vector<int> v3copy = v3;

  assert(v3 == v3copy);
  assert(v == vcopy);
  
  cout << "End ex 3.33" << endl;
}

void sec3_5_3(){
  cout << "Begin sec 3.5.3" << endl;

  int arr[10] = {};
  for(int i = 0; i < 10; i++)
    arr[i] = i;

  auto a = arr; // a is of type pointer
  cout << "Value:" << *a << endl;
  int *beg = a, *e = &a[10];
  for (; beg != e; beg++)
    cout << *beg << " ";
  cout << endl;

  // better using library begin and end, defined in iterator header
  /* Compile error: a is a pointer!
     int *begin1 = std::begin(a), *end1 = std::end(a);
  */
  beg = std::begin(arr), e = std::end(arr);
  for(; beg != e; beg++)
    cout << *beg << " ";
  cout << endl;

  // Operation on pointers is same as on iterators
  beg = std::begin(arr), e = std::end(arr);
  auto mid = beg +  (e - beg)/2;
  for(; beg != mid; beg++)
    cout << *beg << " ";
  cout << endl;

  int ia[] = { 1, 2, 3, 4};
  int last = *(ia + 3);
  assert(last == 4);
  cout << "End sec 3.5.3" << endl;
}

void ex3_34(){
  cout << "Begin ex 3.34" << endl;
  
  int v[] = { 1, 2, 3, 4 };
  int* p1 = v;
  int* p2 = p1 + 2;
  p1 += p2 - p1; // p1 = p1 + p2 - p1
  assert(p2 == p1);

  p2 = std::end(v);
  p1 += p2 - p1;
  cout << "Undefined: " << *p1 << endl;
  
  cout << "End ex 3.34" << endl;
}

void ex3_35() {
  cout << "Begin ex 3.35" << endl;

  int v[] = { 1, 32, 42, 23, 12 };
  for(auto i = std::begin(v); i < std::end(v); i++)
    *i = 0;

  for(auto i : v)
    assert(i == 0);

  cout << "End ex 3.35" << endl;
  
}

void sec3_5_5(){
  cout << "Begin sec 3.5.5" << endl;
  string s("Hello world!");
  const char *c;
  /*
  c = s; //Error
  */
  
  c = s.c_str(); // C-style

  int v[] = {1, 2, 3, 4, 5};
  vector<int> v1(v, std::end(v)); // Copy initilization from int[]
  vector<int> sub(v+3, std::end(v));
  for (size_t i = 0; i < 5; i++)
    assert(v[i] == v1[i]);
  
  cout << "End sec 3.5.5" << endl;
}

int main() {

    sec3_5_1();
    ex3_27();
    ex3_29();
    ex3_31();
    sec3_5_3();
    ex3_34();
    ex3_35();
    sec3_5_5();
    return 1;
}
