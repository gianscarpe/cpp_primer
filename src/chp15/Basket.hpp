#ifndef BASKET_HPP
#define BASKET_HPP


#include "Quote.hpp"
#include <set>
#include <iostream>

class Basket {
public:

  void add_item(const Quote&);

  void add_item(Quote&&);
  
  double total_receipt(std::ostream&) const;
  private:
  static bool compare(const std::shared_ptr<Quote>& lhs, const
		      std::shared_ptr<Quote>& rhs) {
    return lhs->isbn() < rhs->isbn();
  }
  std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items { compare };
};

#endif
