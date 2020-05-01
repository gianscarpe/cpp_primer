#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;

void sec4_5(){
  cout << "Sec 4.5" << endl;

  int i = 1, j = 1;
  i = ++j;
  assert(i == 2);
  assert(j == 2);
  j = 1;
  i = j++;
  assert(i == 1);
  assert(j == 2);

  // Remember: postfix requires extra work. Don't use it unless it's necessary

  vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cbegin();
  
  while(it < v.cend())
    cout << "Value:" << *it++ << endl;


  string s = "Hello how are you?";
  /* FOR implementation
  for(auto it = s.begin(); it != s.end() and !isspace(*it); ++it)
    *it = toupper(*it);
  */

  string s2 = "Hello I love you";

  auto sit = s2.begin();
  while (sit != s2.end() && !isspace(*sit)){
    /* RUNTIME ERROR: both side use sit -> cannot modify it
    *sit = toupper(*sit++);
    */
    *sit = toupper(*sit);
    *sit++;
  }
  cout << "Upper: " << s2 << endl;

  cout << "End" << endl;  
}

void ex4_19(){
  cout << "Ex 4.19" << endl;

  int i1 = 42;
  assert(i1++ && i1 == 43);

  vector<int> v1 = { 1, 2, 3, 4 };
  int index = 0;
  // WARNING: assert(v1[index++] <= v1[index]);
  int* ptr = &i1;
  // ERROR:assert(ptr != 0 && *ptr++ == 43);
  assert(ptr != 0 && (*ptr)++ == 43);


  cout << "End" << endl;
}

int main() {

  sec4_5();
  ex4_19();

  return 1;
}
