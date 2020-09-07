#include "Query.hpp"
#include "textQuery.hpp"
#include "queryResult.hpp"
#include <fstream>
#include <iostream>

using std::ifstream; using std::cout;

void sec15_9(){
  Query q("return");

  ifstream input("textQuery.hpp");
  TextQuery t(input);
  QueryResult r =q.eval(t);
  print(cout, r);
}
int main(){
  sec15_9();
}
