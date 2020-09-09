#include <string>
#include <memory>
#include <vector>
#include <set>
#include <iostream>
#include "queryResult.hpp"

std::ostream& print(std::ostream &out, const QueryResult& r){
  out << "Total number of found: " << r.wc->size() << " ";
  for(auto i : *r.wc){
    std::cout << "(line " << i << ") " << r.lines->at(i) << std::endl;
  }
  return out;
}
