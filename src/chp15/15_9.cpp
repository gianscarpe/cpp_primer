#include "Query.hpp"
#include "Query.hpp"
#include "Query.hpp"
#include <fstream>
#include <iostream>

using std::ifstream; using std::cout; using std::endl;

void sec15_9(){
  Query q1("cout"), q2("result"), q3("endl;");
  Query q = (q1 & q3);
  ifstream input("Query.cpp");
  RangedTextQuery t(input, 0, 10);
  QueryResult r =q.eval(t);
  print(cout, r);
  cout << endl;
}

int main(){
  sec15_9();
}
