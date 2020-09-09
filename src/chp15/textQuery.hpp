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
  using line_no = int;
  virtual QueryResult query(string);
  TextQuery(ifstream &f){
    lines = parseFile(f);
  }
  
protected:
  shared_ptr<vector<string>> parseFile(ifstream&);
  shared_ptr<vector<string>> lines;
  map<string, shared_ptr<set<int>>> m;
};

class RangedTextQuery : public TextQuery{
public:
  RangedTextQuery(ifstream &f, line_no begin, line_no end) : TextQuery(f),
							     first(begin),
							     last(end){}

  QueryResult query(string);
private:
  line_no first, last;
};

#endif
