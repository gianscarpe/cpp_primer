#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using std::string; using std::vector; using std::ifstream; using std::ofstream;
using std::istringstream;
struct Person{
  string name;
  vector<string> phones;
};

void sec8_3_1(){
  string input_file = "input8_3.txt";
  ifstream input(input_file);
  string line, word;
  vector<Person> persons;
  istringstream record;
  if (input.good()){
    while(getline(input, line)){
      Person info;
      record.clear();
      record.str(line);
      record >> info.name;
      while(record >> word)
	info.phones.push_back(word);
      persons.push_back(info);
    }

    for(const auto c : persons){
      std::cout << c.name << std::endl;
      for(const auto p : c.phones)
	std::cout << p << " ";
      std::cout << std::endl;
    }
  }
  else
    std::cerr << "Cannot open file" << std::endl;
  
}

int main(){
  sec8_3_1();
}
