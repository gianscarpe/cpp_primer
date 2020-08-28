#include "Quote.hpp"
#include <string>
#include <iostream>
using std::cout; using std::endl; using std::string; using std::size_t;

Disc_quote::Disc_quote(const string &_book, double _price, size_t qnt,
                       double _discount)  : Quote(_book, _price), min_qt(qnt),
                       discount(_discount) {}

Bulk_quote::Bulk_quote(const string &_book, double _price, size_t qnt,
                       double _discount)  : Disc_quote(_book, _price, qnt, _discount) {}


double Bulk_quote::net_price(size_t cnt) const{
  return (cnt > min_qt) ? cnt * (1 - discount) * price : Quote::net_price(cnt);
}

void Quote::debug(){
  cout << price << " " << bookNo;
}

void Disc_quote::debug(){
  Quote::debug();
  cout << min_qt << " " << discount;
}
