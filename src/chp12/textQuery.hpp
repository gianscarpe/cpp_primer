#ifndef TQ_H
#define TQ_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <istream>
#include <sstream>
#include <memory>
#include "queryResult.hpp"

using std::cin; using std::cout; using std::ifstream; using std::string; using std::endl;
using std::map; using std::vector; using std::set; using std::istringstream;
using std::shared_ptr;

class TextQuery{
public:
  QueryResult query(string);
  TextQuery(ifstream &f){
    lines = parseFile(f);
  }
  
private:
  shared_ptr<vector<string>> parseFile(ifstream&);
  shared_ptr<vector<string>> lines;
  map<string, shared_ptr<set<int>>> m;
};

shared_ptr<vector<string>> TextQuery::parseFile(ifstream &f){
  string line;
  shared_ptr<vector<string>> result(new vector<string>());
  while(getline(f, line))
    result->push_back(line);

  return result;
}

QueryResult TextQuery::query(string in){
  if (m.find(in) != m.end())
    return QueryResult(in, lines, m[in]);
  shared_ptr<set<int>> result(new set<int>());
  for(int i = 0; i != lines->size(); ++i){
    string line = lines->at(i);

    istringstream split(line);
    string word;
    while(split >> word){
      if (word == in)
	result->insert(i);
    }    

  }
  m[in] = result;
  return QueryResult(in, lines, result);
}

#endif
