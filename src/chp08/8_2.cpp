/*
Defining class - 7.1.*

Gianluca Scarpellini - gianluca@scarpellini.dev

*/

#include "Sales_data.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream; using std::ofstream; using std::string; using std::vector;

void sec8_2(int argc, char* argv[]){
  ifstream input(argv[1]);
  ofstream out(argv[2], ofstream::app);
  
  Sales_data data1(input), data2(input);

  Sales_data sum(data1.isbn());
  if (data1.isbn() == data2.isbn()){
    sum.combine(add(data1, data2));

    print(out, sum);
    std::cout << std::endl;
  } else {
    std::cout << "Cannot sum transactions with different bookNo! First: "
              << data1.isbn() << " second: " << data2.isbn() << std::endl;
  }
}
vector<string> process_input(std::istream &in){
  vector<string> read;
  string line;
  while (getline(in, line)){
    read.push_back(line);
  }
  return read;
}

vector<string> store_word(std::istream &in){
  vector<string> read;
  string word;
  while (in >> word)
    read.push_back(word);
  return read;
}

void ex8_4(){
  string file_name = "input8_4.txt";
  ifstream input(file_name);
  if (input.good()){
    vector<string> result = process_input(input);
    std::cout << "Read:" << std::endl;
    for (auto i = result.cbegin(); i != result.cend(); ++i)
      std::cout << *i << std::endl;

  }
  else{
    std::cerr << "Cannot open file" << std::endl;
  }
}


int main(){
  ex8_4();
}
