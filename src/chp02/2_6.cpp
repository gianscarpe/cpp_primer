/*
Defining our data structures - 2.6.*

Gianluca Scarpellini - gianluca@scarpellini.dev
*/

#include <iostream>
#include "Sales_data.h"

void ex_2_41(){
  Sales_data data1, data2;

  double price = 0.0;
  std::cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenew = price * data1.units_sold;

  price = 0.0;
  std::cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenew = price * data2.units_sold;

  if (data1.bookNo == data2.bookNo){
    Sales_data sum;
    sum.bookNo = data1.bookNo;
    sum.revenew = data1.revenew + data2.revenew;
    sum.units_sold = data1.units_sold + data2.units_sold;

    std::cout << "Sum of 2 transactions: " << sum.bookNo << " " <<
      sum.units_sold << " " << sum.revenew << std::endl;
    
  }
  else{
    std::cout << "Cannot sum transactions with different bookNo! First: " <<
      data1.bookNo << " second: " << data2.bookNo << std::endl;
  }


}
void ex_2_6_(){
  std::cout << "BEGIN - EX 2.6." << std::endl;

  std::cout << "ALL PASSED! END - EX 2.6." << std::endl;


}
  
int main(){
  ex_2_41();


  return 1;
}
  
