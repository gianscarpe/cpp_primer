#ifndef QR_H
#define QR_H
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <iostream>
class QueryResult {
public:
  friend std::ostream& print(std::ostream&, const QueryResult& r);
  QueryResult(std::string s, std::shared_ptr<std::vector<std::string>> _lines,
              const std::shared_ptr<std::set<int>> _wc)
    : query(s), lines(_lines), wc(_wc) {};

private : std::string query;
  std::shared_ptr<std::vector<std::string>> lines;
  std::shared_ptr<std::set<int>> wc;
};

std::ostream& print(std::ostream &out, const QueryResult& r){
  out << "Total number of found: " << r.wc->size() << " ";
  for(auto i : *r.wc){
    std::cout << "(line " << i << ") " << r.lines->at(i) << std::endl;
  }
  return out;
}


#endif
