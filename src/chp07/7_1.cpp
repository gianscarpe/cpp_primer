/*
Defining class - 7.1.*

Gianluca Scarpellini - gianluca@scarpellini.dev

*/

#include "Sales_data.h"
#include <iostream>

/*
void ex_7_2(){
  Sales_data data1, data2;

  double price = 0.0;
  std::cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = price * data1.units_sold;

  price = 0.0;
  std::cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = price * data2.units_sold;


  if (data1.bookNo == data2.bookNo){
    Sales_data sum;
    sum.bookNo = data1.bookNo;
    sum.revenue = data1.revenue + data2.revenue;
    sum.units_sold = data1.units_sold + data2.units_sold;

    std::cout << "Sum of 2 transactions: " << sum.bookNo << " " <<
      sum.units_sold << " " << sum.revenue << std::endl;
    
  }
  else{
    std::cout << "Cannot sum transactions with different bookNo! First: " <<
      data1.bookNo << " second: " << data2.bookNo << std::endl;
  }


}


void ex_7_7(){
  Sales_data data1, data2;

  read(std::cin, data1);
  read(std::cin, data2);

  if (data1.isbn() == data2.isbn()){
    Sales_data sum = add(data1, data2);
    
    std::cout << "Sum of 2 transactions: ";
    print(std::cout, sum);
  }
  else{
    std::cout << "Cannot sum transactions with different bookNo! First: " <<
      data1.isbn() << " second: " << data2.isbn() << std::endl;
  }
}
*/
void ex_7_11(){
  Sales_data data1(std::cin), data2(std::cin);

  Sales_data sum(data1.isbn());
  if (data1.isbn() == data2.isbn()){
    sum.combine(add(data1, data2));

    
    std::cout << "Sum of 2 transactions: ";
    print(std::cout, sum);
    std::cout << std::endl;
  } else {
    std::cout << "Cannot sum transactions with different bookNo! First: "
              << data1.isbn() << " second: " << data2.isbn() << std::endl;
  }
}

int main(){
  //ex_7_2();
  //ex_7_7();
  ex_7_11();
    
}
