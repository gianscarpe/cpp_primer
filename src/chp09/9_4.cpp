#include <vector>
#include <iostream>

using std::vector; using std::cin; using std::cout; using std::endl;

void print_info(vector<int> v){
  cout << "V size: " << v.size() << " ; V capacity: " << v.capacity() << endl;
}

void ex9_38(){
  vector<int> v;
  print_info(v);

  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  print_info(v);
  while (v.size() != v.capacity())
    v.push_back(42);
  print_info(v);
  v.push_back(42);
  print_info(v);
  
  v.reserve(10);
  print_info(v);
    
}

int main(){
  ex9_38();
  return 1;
}
