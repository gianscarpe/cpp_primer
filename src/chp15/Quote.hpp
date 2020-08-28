#ifndef QUOTE_HPP
#define QUOTE_HPP
#include <string>
class Quote { 
public: 
  Quote() = default;  // = default  see § 7.1.4 (p. 264) 
  Quote(const std::string &book, double sales_price): 
    bookNo(book), price(sales_price) { } 
  std::string isbn() const { return bookNo; } 
  // returns the total sales price for the specified number of items 
  // derived classes will override and apply different discount algorithms
  virtual double net_price(std::size_t n) const   { return n * price; } 
  virtual ~Quote() = default; // dynamic binding for the destructor private:
  virtual void debug();
  std::string bookNo; // ISBN  number of this item
  
protected: 
  double price = 0.0; // normal, undiscounted price 
};


class Disc_quote : public Quote{
public:
  Disc_quote() = default;
  Disc_quote(const std::string&, double, std::size_t, double);
  double net_price(std::size_t) const override = 0;
  virtual void debug() override;
protected:
  std::size_t min_qt = 0;
  double discount = 0.0;
};



class Bulk_quote : public Disc_quote{
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string&, double, std::size_t, double);
  double net_price(std::size_t) const override;
};

#endif
