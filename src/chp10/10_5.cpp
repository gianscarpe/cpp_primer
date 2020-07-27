#include <list>
#include <iostream>

using std::list; using std::cout; using std::endl;

void ex10_42(){
  list<int> l = { 1, 2, 3, 4, 5, 6, 1, 3, 5};
  l.sort();
  l.unique();
  for (int i : l)
    cout << i << " ";
  cout << endl;
}

int main(){
  ex10_42();
  return 1;
}
