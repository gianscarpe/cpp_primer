#include "Sales_data.hpp"
#include <iostream>
#include <string>

using std::string;

double Sales_data::avg_price() const {
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
  
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs){
  Sales_data tot(lhs);
  tot+=rhs;
  return tot;
}



Sales_data& Sales_data::operator+=(const Sales_data& rhs){
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data& Sales_data::operator=(const string s){
  bookNo = s;
  return *this;
}

std::istream& read(std::istream &is, Sales_data &item){
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  std::cout << "READ: " << item << std::endl;
  item.revenue = price * item.units_sold;
  return is;
  
}

std::ostream& operator<<(std::ostream& is, const Sales_data& item){
  return print(is, item);
}


std::istream& operator>>(std::istream& os, Sales_data& item){
  return read(os, item);
}


std::ostream& print(std::ostream &os, const Sales_data &item){
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "  <<
    item.avg_price(); 
  return os;
}

Sales_data add(const Sales_data &s1, const Sales_data &s2){
  Sales_data sum = s1 + s2;
  return sum;

}
 
