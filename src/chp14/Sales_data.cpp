#include "Sales_data.hpp"
#include <iostream>

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

std::istream& read(std::istream &is, Sales_data &item){
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  std::cout << "READ: " << item << std::endl;
  item.revenue = price * item.units_sold;
  return is;
  
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs){
  return !(lhs == rhs);
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs){
  return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold &&
    lhs.revenue == rhs.revenue;
  
}

std::ostream& operator<<(std::ostream& is, const Sales_data& item){
  return print(is, item);
}


std::istream& operator>>(std::istream& is, Sales_data& item){

  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  if (is) {
    item.revenue = price * item.units_sold;
    std::cout << "READ: " << item << std::endl;
  }
  else
    item = Sales_data();
  return is;
 
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
 
