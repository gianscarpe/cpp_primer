#include <iostream>
#include <string>
#include <cctype>
using std::cin; using std::cout; using std::endl; using std::string;

void sec4_3(){
  cout << "Begin sec 4.3" << endl;
  const string text[] = {"ciao", "come", "", "mondo", "."};

  for(const string &s : text){
    cout << s;
    if (s.empty() || ispunct((*s.end())))
      cout << endl;
    else
      cout << " ";
  }
  cout << endl;

  cout << "End sec 4.3" << endl;
}

void ex4_9(){
  cout << "Begin ex 4.9" << endl;
  const char *cp = "Hello world";
  if (cp && *cp)
    cout << "True because both can be casted to int (and as a consequence tobool) and have value != 0";

  cout << "End ex 4.9" << endl;
}

void ex4_12(){
  cout << "Begin ex 4.12" << endl;

  int i = 1, j = 23, k = 31;
  bool r = i != j < k; // i != (j < k) -> i != (0 if j < k, 1 otherwise)
  cout << "Result: " << r << "" << endl;
  cout << "End ex 4.12" << endl;
    
}

int main(){

  sec4_3();
  ex4_9();
  ex4_12();
  return 1;
}
