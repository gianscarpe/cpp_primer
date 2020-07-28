#include <iostream>
#include <fstream>
#include "textQuery.hpp"
#include "queryResult.hpp"
#include <string>
#include <memory>

using std::cin; using std::cout; using std::ifstream; using std::string; using std::endl;
using std::ostream; using std::shared_ptr;
std::ostream& print(std::ostream &out, const QueryResult& r){
  out << "Total number of found: " << r.wc->size() << " ";
  for(auto i : *r.wc){
    cout << "(line " << i << ") " << r.lines->at(i) << endl;
  }
  return out;
}


void runQueries(ifstream &in){
  TextQuery tq(in);
  string query;
  while(true){
    cout << "Input your word or q to end the program:" << endl;
    cin >> query;
    if (query == "q")
      break;
    print(cout, tq.query(query)) << endl;
  }
}


int main(){
  ifstream inputFile("input.txt");
  runQueries(inputFile);
}
