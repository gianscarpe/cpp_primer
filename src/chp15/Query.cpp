#include "Query.hpp"
#include <iostream>

using std::make_shared;
using std::cout; using std::endl;

QueryResult OrQuery::eval(TextQuery& text) const
{
  cout << "OR query " << rep() << endl;
  auto right = rhs.eval(text), left = lhs.eval(text);
  
  auto ret_lines =
    make_shared<set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), left.get_file(), ret_lines);

}

QueryResult AndQuery::eval(TextQuery& text) const
{
  cout << "AND query " << rep() << endl;
  auto right = rhs.eval(text), left = lhs.eval(text);
  auto ret_lines =
    make_shared<set<line_no>>();
  std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
			std::inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), left.get_file(), ret_lines);
}

QueryResult
NotQuery::eval(TextQuery& text) const
{
  cout << "NOT query " << rep() << endl;
  auto result = query.eval(text);
  auto ret_lines = make_shared<set<line_no>>();
  auto beg = result.begin(), end = result.end();
  auto sz = result.get_file()->size();
  for(size_t n = 0; n != sz; ++n){
    if (beg == end || *beg!=n)
      ret_lines->insert(n);
    else if (beg != end)
      ++beg;
  }
  return QueryResult(rep(), result.get_file(), ret_lines);

}

std::ostream& operator<<(std::ostream& os, const Query &query){
  return os << query.rep();
  
}



