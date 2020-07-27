#include <set>
#include <map>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::map; using std::list; using std::cin; using std::cout; using
std::endl; using std::string; using std::vector;
using std::multiset; using std::copy;


void ex11_9(){
  map<string, list<int>> occurrence;

  occurrence["ciao"] = { 1, 2, 3 };
  
    
}

void ex11_10(){

  map<vector<int>::iterator, int> v1;
  map<list<int>::iterator, int> v2;

  vector<int> v = { 1, 2, 3 };
  list<int> l = {1, 2, 3};
  v1[v.begin()] = 2;
  /* cannot compare list iterators!
     v2[l.begin()] = 2;
  */
  
}


void ex11_17(){
  vector<string> v = {"ciao", "come", "va", "ciao"};
  multiset<string> c;
  
  copy(v.begin(), v.end(),
       std::inserter(c, c.end()));
  // CANNOT push_back in multiset
  //copy(v.begin(), v.end(), std::back_inserter(c));
  copy(c.begin(), c.end(), std::inserter(v, v.end()));
  copy(c.begin(), c.end(), std::back_inserter(v));
  
}

bool compare(string s1, string s2){
  return s1.size() < s2.size();
}

void ex11_19(){
  multiset<string, bool (*) (string, string)> m(compare);
  m.insert("ciao");
  m.insert("ciao");
  m.insert("ciao");
  m.insert("c");
  for (string s : m)
    cout << s << " ";
  cout << endl;
  const multiset<string, bool (*) (string, string)>::iterator b = m.begin();
  cout << (*b) << endl;
}

int main() {
  ex11_9();
  ex11_10();
  ex11_19();
  ex11_17();
  return 1;
}
