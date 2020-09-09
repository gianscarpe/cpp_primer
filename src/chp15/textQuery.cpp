#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <istream>
#include <sstream>
#include <memory>
#include "textQuery.hpp"
#include "queryResult.hpp"

using std::cin; using std::cout; using std::ifstream; using std::string; using std::endl;
using std::map; using std::vector; using std::set; using std::istringstream;
using std::shared_ptr;


shared_ptr<set<int>> search(const vector<string>::iterator begin,
			    const vector<string>::iterator end, string in){
  shared_ptr<set<int>> result(new set<int>());
  int i = 0;
  
  for(auto it = begin; it != end; ++it, ++i){
    string line = *it;

    istringstream split(line);
    string word;
    while (split >> word) {
      if (word == in)
        result->insert(i);
    }
  }
  return result;

}


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
  
  auto result = search(lines->begin(), lines->end(), in);
  m[in] = result;
  return QueryResult(in, lines, result);
}


QueryResult RangedTextQuery::query(string in){
  if (m.find(in) != m.end())
    return QueryResult(in, lines, m[in]);
  auto result = search(lines->begin() + first, lines->begin() + last, in);
  m[in] = result;
  return QueryResult(in, lines, result);
}
  

