#include <list>
#include <deque>
#include <string>
#include <vector>
#include <iostream>

using std::list; using std::deque; using std::string; using std::vector;

void ex9_2(){
  list<deque<int>> l;
  
}

void sec9_2_4(){
  list<string> authors = {"Milton", "Shakespeare", "Austen"};
  vector<const char*> articles = {"a", "an", "the"};
  
  // deque<string> authList(authors);
  // vector<string> words(authors.);   
  list<string> l(articles.begin(), articles.end());
}

void ex9_13(){
  list<int> l = { 1, 2, 3, 4 };
  vector<double> v(l.begin(), l.end());
  vector<int> vinit(10, 42);


  vector<double> v2(vinit.begin(), vinit.end());
}

void ex9_14(){
  list<char *> l;
  vector<string> v;
  v.assign(l.begin(), l.end());

}

void ex9_16(){
  list<int> l = { 1, 2, 3, 4, 5 };
  vector<int> v = {1, 2, 3, 4, 5};

  int result = vector<int>(l.begin(), l.end()) < v;
  std::cout << result << std::endl;

}
int main(){
  ex9_2();
  ex9_16();
  return 1;
}
