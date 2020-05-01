#include <vector>
#include <iostream>
#include <cctype>

using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;


void sec3_1_1(){
  cout << "Begin ex 3.1.1" << endl;
  vector<int> ivec(4, 0);
  vector<int> ivec2{ 0, 0, 0, 0 };
  vector<int> ivec3(4);

  assert(ivec == ivec2);
  assert(ivec2 == ivec3);
  cout << "PASSED! End ex 3.1.1" << endl;

}

void sec3_3_2(){
  cout << "Begin sec 3.3.2" << endl;
  // Vectors basics
}


void ex3_13(){
  cout << "Begin ex 3.13" << endl;
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10, 42);
  vector<int> v4 { 10 };
  vector<int> v5 { 10, 42 };
  vector<string> v6 { 10 };
  vector<string> v7 { 10, "hi" };
  
  /* Compile error
     vector<string> v8{10, 42};
  */

  assert(v1.size() == 0);
  assert(v2.size() == 10);
  assert(v3.size() == 10);
  assert(v4.size() == 1);
  assert(v5.size() == 2);
  assert(v6.size() == 10);
  assert(v7.size() == 10);

  cout << "PASSED! End ex 3.13" << endl;
}

void ex3_14(){
  cout << "Ex 3.14" << endl;
  vector<int> inputs;
  int newValue;
  cout << "Insert values" << endl;
  while(cin >> newValue)
    inputs.push_back(newValue);

  cout << "Your inputs: " << endl;
  for(int value : inputs)
    cout << value << " " << endl;
  
  cout << "End ex 3.14" << endl;

}

void sec3_3_3(){
  cout << "Begin sec 3.3.3" << endl;
  vector<unsigned> grades;
  vector<unsigned> results(11,0);
  unsigned grade, max_grade=100;
  decltype(results.size()) index;

  while (cin >> grade){
    if (grade <= max_grade) {
      grades.push_back(grade);
      index = grade / 10;

      results[index]++;
    }
  }
  for(auto r : results)
    cout << r << endl;

  cout << "End sec 3.3.3" << endl;
  

}

void ex3_17() {
  cout << "Begin ex 3.17" << endl;
  
  vector<string> words;
  string input;
  cout << "Words: " << endl;

  while (cin >> input)
    words.push_back(input);

  cout << "TO UPPERCASE" << endl;
  for (auto &word : words)
    for (auto &c : word)
      c = toupper(c);

  decltype(words.size()) index, print_every=8;
  for (index = 0; index != words.size(); ++index)
    if (index % print_every == 0)
      cout << endl << words[index];
    else
      cout << words[index] << " ";

  cout << endl;
  cout << "End ex 3.17" << endl;

}

void ex3_20(){
  cout << "Begin ex 3.20" << endl;
  
  vector<int> inputs;
  int input;
  while (cin >> input)
    inputs.push_back(input);

  decltype(inputs.size()) index=0;
  for(; index < inputs.size() -1; ++index)
    cout << inputs[index] + inputs[index+1] << " ";
  cout << endl;
  
  decltype(inputs.size()) mid_size = inputs.size()/2;
  for(index=0; index < mid_size; ++index)
    cout << inputs[index] + inputs[inputs.size()-index] << " ";
  cout << endl;

  cout << "End ex3.20" << endl;
}

int main(){

  sec3_1_1();
  ex3_13();
  sec3_3_2();
  //ex3_14();
  //sec3_3_3();
  //ox3_17();
  ex3_20();
  
  return 1;

}
