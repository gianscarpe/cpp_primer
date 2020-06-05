#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <initializer_list>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

void print(string);
void print(const string); // same as before

void print(string*);
void print(string* const); // same as before

// BUT
void print(const string*); // pointer to const string != const pointer to string

/* ex 6.39: Overloading is not possible here
  int get();
  double get();
*/
