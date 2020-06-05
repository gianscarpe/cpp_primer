#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <initializer_list>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;
using std::initializer_list;

void reset(int& v1){
  v1 = 0;
}

void refToConstExample(const int& l){
  cout << l << endl;
}

void swap(int& v1, int& v2){
  int tmp = v1;
  v1 = v2;
  v2 = tmp;
}

bool isShorter(const string &s1, const string &s2){
  return s1.size() < s2.size();
}

bool is_empty(const string &s1){
  return s1.size() > 0;
}

bool containes_capital(const string &s1){
  for(auto c : s1){
    if (isupper(c))
      return true;
  }
  return false;
}

void to_lower(string &s1){
  for(auto &c : s1)
    c = tolower(c);
    
}

void ex6_10(){
  cout << "Begin ex 6.10" << endl;
  int v1 = 10, v2 = 20;
  swap(v1, v2);
  assert(v2 == 10);
  assert(v1 == 20);
}

string::size_type find_char(const string &s, char c, string::size_type &occ){
  decltype(s.size()) ret = s.size();
  int count = 0;
  for (decltype(s.size()) i = 0; i != s.size(); ++i){
    if (s[i] == c) {
      if (ret == s.size())
	ret = i;
      ++occ;
      
    }
  }
  return ret;
}


void sec6_2_2(){
  cout << "Begin sec 6.2.2" << endl;
  string s1 =  "hi";
  string s2 = "hello";
  assert(isShorter(s1, s2));

  string::size_type occ = 0;
  auto t = find_char(s2, 'l', occ);
  cout << "Occurrance: " << occ << " first occ: " << t << endl;
  assert(occ == 2);
  assert(s2[t] == 'l');
  
  
}


void sec6_2_3(){
  cout << "Begin sec 6.2.3" << endl;
  int i = 42;
  reset(i);
  assert(i == 0);
  int j = 42;
  const int& c=  j;
  unsigned cnt = 13;

  /* Would lose const qualifier
     reset(c);
  */

  /* Cannot convert from unsigned to int
    reset(cnt);
  */

  refToConstExample(42); // We can pass literals IF reference argument is CONST
 
}

class matrix {};

vector<int> change_val(const int v, vector<int>::iterator vector);
bool compare(const matrix &m1, const matrix &m2);
  

void ex6_17(){
  cout << "Begin ex 6.17" << endl;
  assert(containes_capital("Hi my dear"));
  string s1 = "HELLO";
  to_lower(s1);
  assert(s1 == "hello");
  string * const p1 = &s1; // const pointer to string
  const string * p2 = &s1; // pointer to const string
  to_lower(*p1); // legal
  // to_lower(*p2); // unlegal
  
}


/*
bool calc(double);
int sum(vector<int>::iterator, vector<int>::iterator, int);

void ex6_19(){
  calc(66); // legal
  vector<int> v1 { 10, 10 };
  sum(v1.begin(), v1.end(), 42); // legal BUT you can use reference to const (?)
}

*/
void f1(const int v1){
  // ...
}

/* Compile error: redefinition of f1
void f1(int v1){
  // ...
}
*/

void print_array(const int* beg, const int* end){
  while(beg < end)
    cout << *beg++ << " ";
  cout << endl;
  
}

// using references
void print_array(const int (&arr)[5]){
  for(auto i : arr)
    cout << i << " ";
  cout << endl;

}

// REMEMBER: size of an array is PART of the declaration -> if you want to print
// multidimensional array you have to specify all the dimensions (except the
// first one, because is a pointer to array)
void print_matrix(const int matrix[][5], int n_rows){
  for(int i = 0; i != n_rows; ++i){
    cout << "Row n. " << i+1 << endl;
    print_array(matrix[i]);
  }
}

void sec6_2_4(){
  cout << "Begin sec 6.2.4" << endl;
  int arr[5] = { 1, 2, 3, 4, 5 };
  print_array(std::begin(arr), std::end(arr) );
  print_array(arr);

  int matrix[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  print_matrix(matrix, 2);
}

int max(int v1, const int *v2){
  return (v1 > *v2) ? v1 : *v2;
}

void ex6_21(){
  cout << "Begin ex 6.21" << endl;
  int v1 = 15;
  int tmp = 42;
  int *v2 = &tmp;
  assert(max(v1, v2) == *v2);
  
}

void print(const int ia[10]){ // It works, but it's better to write it as print_array
  for(size_t i = 0; i != 10; ++i){
    cout << ia[i] << endl;
  }
}

// Better alternative to print
void print(const int* ia, int n){
  for(size_t i = 0; i != n; ++i){
    cout << *(ia + i) << endl;
  }
}

void ex6_24(){
  cout << "Begin ex 6.24" << endl;
  int ia[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(ia);
  print(ia, 10);
}

void print_parameters(int n, char *args[]){
  for (int i = 0; i != n; ++i) {
    // cout << *args[i];
    while (*args[i])
      cout << *(args[i]++);
    cout << endl;
  }
  cout << "END parameters" << endl;
}

void concatenate(int n, char *args[], string* result){
  for (int i = 0; i != n; ++i) {
    string tmp = "";
    while (*args[i])
      tmp += *(args[i]++);
    cout << tmp;
    *result += " " + tmp;
  }
}

void print_messages(initializer_list<string> msgs){
  for(auto s : msgs)
    cout << s << " ";
  cout << endl;
}

void sec6_2_6(){
  cout << "Begin sec 6.2.6" << endl;
  string s1 = "hi", s2 = "how";
  print_messages({s1, s2});
  print_messages({
		  "Note that", "do not use reference", "litterals are allowd"});
}

int sum(initializer_list<int> values){
  int result = 0;
  for(initializer_list<int>::iterator it = values.begin(); it != values.end(); ++it){
    result+=*it;
  }
  return result;
    
}

void ex6_26(){
  cout << "Ex 6.26" << endl;
  cout << sum({
	       1, 2, 3, 4, 5, 6}) << endl;;
  assert(sum({
	      1, 2, 3, 4, 5, 6}) == (6 * 7 / 2 ));
}

int main(int argc, char* argv[]){
  cout << "parameters:" << argc << endl;
  //print_parameters(argc, argv);
  string s = "Our parameters: ";
  concatenate(argc, argv, &s);
  cout << s << endl;
  ex6_10();
  sec6_2_2();
  sec6_2_3();
  ex6_17();
  sec6_2_4();
  ex6_21();
  ex6_24();
  sec6_2_6();
  ex6_26();
  return EXIT_SUCCESS;
}
