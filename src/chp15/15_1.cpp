#include <iostream>
#include "Quote.hpp"
using std::cout; using std::endl;

void print_total(std::ostream& os, const Quote& item, size_t n){
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " total: " << ret << endl;
}
void sec15_1(){
  Quote q1("ciao", 3.2);
  Bulk_quote q2("ciao", 3.2, 5, .5);
  print_total(cout, q1, 10);
  print_total(cout, q2, 10);
}

int main(){
  sec15_1();
}
