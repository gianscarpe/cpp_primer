#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

using std::vector; using std::cout; using std::count; using std::list; using std::string;

void ex10_1(){
  vector<int> v = { 1, 2, 3, 2 };
  int c = count(v.cbegin(), v.cend(), 2);
  assert(c == 2);
}

void sec10_2_1(){
  vector<int> v = { 1, 2, 3, 2 };
  int c = std::accumulate(v.cbegin(), v.cend(), 0);
  assert(c == 8);

  list<string> s = {"as", "asds"};

  string r = std::accumulate(s.cbegin(), s.cend(), string(""));
  assert(r == "asasds");

  vector<double> d = {1.2, 3.1};
  // Note: the initial value is INT, therefore summation is done over int values
  double acc_d = std::accumulate(d.cbegin(), d.cend(), 0); 
  assert(acc_d == 4.0); // int value
  double acc_d_right = std::accumulate(d.cbegin(), d.cend(), 0.0);
  assert(acc_d_right == 4.3);
}

int main(){

    ex10_1();
    sec10_2_1();
    return 1;
  }
