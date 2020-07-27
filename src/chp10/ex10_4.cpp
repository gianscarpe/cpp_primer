#include <vector>
#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <fstream>

using std::vector; using std::cin; using std::cout; using std::endl; using std::list;
using std::deque; using std::string; 

void ex10_27(){
  list<int> l = {1, 2, 3, 4, 5};
  deque<int> v = {10, 11};

  // USING front_iterator
  std::unique_copy(l.begin(), l.end(), std::inserter(v, v.end()));
  for(int i : v)
    cout << i << " ";
  cout << endl;
}

void sec10_4_2(){
  std::istream_iterator<int> in(cin);
  std::istream_iterator<int> eof;
  vector<int> v(in, eof);

  std::ostream_iterator<int> out(cout, " ");
  for(int i : v)
    *out++ = i;
  cout << endl;
  // OR we can use COPY
  std::copy(v.cbegin(), v.cend(), out);
  cout << endl;

}


void ex10_33(const char* input_file, const char* output_even, const char* output_odd){
  std::ifstream file_in(input_file);
  std::istream_iterator<int> in(file_in);
  std::istream_iterator<int> eof;

  std::ofstream file_even(output_even);
  std::ofstream file_odd(output_even);
    
  std::ostream_iterator<int> out_even(file_even, " ");
  std::ostream_iterator<int> out_odd(file_odd, " ");
  std::ostream_iterator<int> out(cout, " ");
  
  vector<int> v(in, eof);
  std::sort(v.begin(), v.end());
  auto is_even = [](int v) { return v % 2 == 0;};
  auto curr_evens = std::partition(v.begin(), v.end(), is_even);
  std::copy(v.begin(), curr_evens, out_even);
  std::copy(curr_evens, v.end(), out_odd);
  
  cout << "Alls" << endl;
  std::copy(v.begin(), v.end(), out);
  cout << endl;
  cout << "Evens" << endl;
  std::copy(v.begin(), curr_evens, out);
  cout << endl;
  cout << "Odds" << endl;
  std::copy(curr_evens, v.end(), out);
  cout << endl;
  

}

void ex10_37(){
  vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  
  list<int> l(v.rbegin() + 3, v.rbegin() + 8);


  for(auto it = v.crbegin(); it != v.crend(); ++it)
    cout << *it << " ";
  cout << endl;

  for(auto it = v.cend(); it != v.cbegin(); --it)
    cout << *it << " ";
  cout << endl;

  
  for(int i : l)
    cout << i << " ";
  cout << endl;
}

int main(){
  ex10_27();
  //  sec10_4_2();
  ex10_33("input.txt", "o1.txt", "o2.txt");
  ex10_37();
}
