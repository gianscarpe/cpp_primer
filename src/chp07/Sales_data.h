#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

class Sales_data {
  
public:
  Sales_data() = default;
  Sales_data(std::istream&);
  Sales_data(const std::string &s) : bookNo(s) {};
  Sales_data(const std::string &s, const unsigned sold, const double p) :
    bookNo(s), revenue(p * sold), units_sold(sold) {};
  
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  
};
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);


#endif
