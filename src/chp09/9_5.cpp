#include <string>
#include <vector>
#include <iostream>
#include <stack>

using std::string; using std::vector; using std::cin; using std::cout; using std::endl;
using std::stack;


void ex9_41() {

  vector<char> c = {'a', 'b', 'c'};
  string s(&c[0], 3);
  // OR
  string s2(&c[0]);
  
  cout << s << endl;

}

void ex9_50(){
  vector<string> s = { "23213", "35432", "23423.23", "2w54432", "234" };
  int sum = 0;
  for(auto v : s)
    sum += stoi(v);
  cout << "Sum: " << sum << endl;
}

void ex9_52() {
  string s = "(( asdasf + asfs ))";
  stack<char> stk;

  char top;
  int error = 0;
  
  cout << "Start parsing" << endl;
  for(const char c : s){
    if (c == '(')
      stk.push(c);
    if (c == ')'){
      if (!stk.empty()){
	top = stk.top();
	if (top == '(')
	  stk.pop();
	else
	  ++error;
      }
      else
	++error;
    }
  }
  cout << "Errors:" << error << endl;
}

int main(){
  ex9_41();
  ex9_50();
  ex9_52();
  return 1;
}
