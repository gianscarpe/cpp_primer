#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>


class Sales_data {
  friend Sales_data add(const Sales_data&, const Sales_data&);
  friend std::ostream &print(std::ostream&, const Sales_data&);
  friend std::istream &read(std::istream&, Sales_data&);

  friend std::ostream &operator<<(std::ostream&, const Sales_data&);  
  friend std::istream &operator>>(std::istream&, Sales_data&);
  
  friend Sales_data operator+(const Sales_data&, const Sales_data&);
  friend bool operator==(const Sales_data&, const Sales_data&);
  friend bool operator!=(const Sales_data&, const Sales_data&);
public:

  Sales_data(const std::string &s, const unsigned sold, const double p) :
    bookNo(s), revenue(p * sold), units_sold(sold) {};
  Sales_data() : Sales_data("", 0, 0) {};
  Sales_data(const std::string &s) : Sales_data(s, 0, 0) {};
  Sales_data(std::istream &is) : Sales_data(){is >> *this;} ;
  Sales_data& operator+=(const Sales_data&);
  std::string isbn() const { return bookNo; }
  explicit operator std::string() const { return bookNo; }
  explicit operator double() const { return avg_price(); }

private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  
};



#endif
