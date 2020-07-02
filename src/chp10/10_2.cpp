
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "../chp08/Sales_data.hpp"

using std::vector; using std::cin; using std::cout; using std::endl; using std::string;


void sec10_2_2(){
  vector<int> v;
  /* Error: undefined! Algorithms don't change container size
    std::fill_n(v.begin(), 10, 42);	
  */

  // Insertion iterator
  auto it = std::back_inserter(v);
  std::fill_n(it, 10, 42);
  for (int i : v)
    cout << i << " ";
  cout << endl;

  // Copy
  vector<int> d;
  // Don't work, because d doesn't have enough space for v!
  // std::copy(v.begin(), v.end(), d); 

  // You can use back_inserter
  std::copy(v.begin(), v.end(), back_inserter(d));
}

void ex10_7(){
  vector<int> d;
  // Note: reserve doesn't increase actual size!
  // d.reserve(10);
  std::fill_n(std::back_inserter(d), 10, 0);
  for (int i : d)
    cout << i << " ";
  cout << endl;
}

void sec10_2_3(){
  vector<string> v = {"the", "the", "what", "what", "does", "the", "fox", "say", "to", "the", "dog",
		      "?" };
  // Eliminate duplicates
  std::sort(v.begin(), v.end());
  auto cur = std::unique(v.begin(), v.end());
  v.erase(cur, v.end());
  
  for (string i : v)
    cout << i << " ";
  cout << endl;
  
}

bool compareIsbn(Sales_data i1, Sales_data i2){
  return i1.isbn() < i2.isbn();
}

void ex10_12(){

  vector<Sales_data> v;
  v.push_back(Sales_data(cin));
  v.push_back(Sales_data(cin));
  v.push_back(cin);
  std::sort(v.begin(), v.end(), compareIsbn);
  for (const Sales_data c : v)
    print(cout, c);
  cout << endl;
}


int main(){
  sec10_2_2();
  ex10_7();
  sec10_2_3();
  ex10_12();
  
  return 1;
}
