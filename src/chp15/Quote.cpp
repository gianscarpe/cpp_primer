#include "Quote.hpp"
#include <string>
#include <iostream>
#include <utility>

using std::cout; using std::endl; using std::string; using std::size_t;

Quote::Quote(const Quote& q){
  cout << "Copy c. of quote" << endl;
  bookNo = q.bookNo;
  price = q.price;
}

Quote& Quote::operator=(const Quote& q){
  cout << "Copy assignment of quote" << endl;
  bookNo = q.bookNo;
  price = q.price;

  return *this;
}

Quote& Quote::operator=(Quote&& q){
  if (&q != this){
    cout << "Move assignment of quote" << endl;
    bookNo = std::move(q.bookNo);
    price = q.price;
  }
  return *this;
}

Quote::~Quote(){
  cout << "Destructor of quote" << endl;
}


Disc_quote::Disc_quote(const string &_book, double _price, size_t qnt,
                       double _discount)  : Quote(_book, _price), min_qt(qnt),
                       discount(_discount) {}

Bulk_quote::Bulk_quote(const string &_book, double _price, size_t qnt,
                       double _discount)  : Disc_quote(_book, _price, qnt, _discount) {}


Bulk_quote::Bulk_quote(const Bulk_quote& rhs): Disc_quote(rhs){
  cout << "Copy c. of bulk quote" << endl;
}

Bulk_quote::Bulk_quote(Bulk_quote&& rhs): Disc_quote(std::move(rhs)){
  cout << "Move c. of bulk quote" << endl;
}


Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs){
  cout << "Copy assignment of bulk quote" << endl;
  Disc_quote::operator=(rhs);
  return *this;
}


Bulk_quote& Bulk_quote::operator=(Bulk_quote&& rhs){
  cout << "Move assignment of bulk quote" << endl;
  Disc_quote::operator=(std::move(rhs));

  // Undefined behaviour:
  cout << rhs.isbn() << endl;
  // OK!
  cout << rhs.net_price(10) << endl;
    
  return *this;
}



Bulk_quote::~Bulk_quote(){
  cout << "Destructor of bulk quote" << endl;
}

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
