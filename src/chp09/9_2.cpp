#include <list>
#include <deque>
#include <string>
#include <vector>

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

int main(){
  ex9_2();
  return 1;
}
