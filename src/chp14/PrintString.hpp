#ifndef PS_HPP
#define PS_HPP
#include <iostream>
#include <string>

class PrintString {
public:
  PrintString(std::ostream &_os = std::cout, char c = ' ') : os(_os), sep(c) {}
  PrintString(char c = ' ') : os(std::cout), sep(c) {}
  void operator()(const std::string &s) { os << s << sep; }

private:
  std::ostream &os;
  char sep;
};

#endif
