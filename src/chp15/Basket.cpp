
#include "Basket.hpp"
#include <iostream>

using std::ostream; using std::cout; using std::endl;



double Basket::total_receipt(ostream& os) const {
  double sum = 0.0, item_net = 0.0;
  for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
    item_net = (*iter)->net_price(items.count(*iter));

    cout << "TOTAL for item " << (*iter)->isbn() << " for quantatiy " <<
      items.count(*iter) << " is " << item_net << endl;
    sum += item_net;
  }
  

  return sum;
}
  

void Basket::add_item(const Quote& sale){
  items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote&& sale){
  items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
}
