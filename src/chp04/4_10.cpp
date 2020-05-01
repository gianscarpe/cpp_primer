#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;


void ex4_31(){
  cout << "Ex 4.31" << endl;

  vector<int> v = {1, 2, 3, 4, 5};
  vector<int>::size_type n = v.size();
  
  for(decltype(v.size()) i = 0; i != v.size(); ++i, --n)
	v[i] = n;


  n = v.size();
  
  for(decltype(v.size()) i = 0; i != v.size(); i++, n--)
	v[i] = n;


  
  for(vector<int>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
    cout << *it << " ";
  cout << endl;
}

void ex4_33(){
  cout << "Begin ex 4.33" << endl;

  int a = 0, b = 1, c = 2;
  int vl = (a==0 ? ++b, ++c : --b, --c);
  // equivalent to (someValue ? (++x, ++y) : --x) , --y
  // comma has lower precedent then ?:
  cout << vl << endl;
  assert(vl == 2);
}


void sec4_10(){
  cout << "Ex 4.28" << endl;
  int i = 0;
  cout << "Number:" <<  (i++, i) << endl;
}

int main(){

  sec4_10();
  ex4_31();
  ex4_33();
  return 1;
}
