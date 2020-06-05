#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person {
  friend std::ostream &print(std::ostream&, const Person&);
  friend std::istream &read(std::istream&, Person&);

public:
  Person() = default;
  Person(std::istream&);
  Person(const std::string &_name, const std::string &_address)
    : name(_name), address(_address) {};
  std::string getName() const { return name;}
  std::string getAddres() const { return address;}
private:
  std::string name;
  std::string address;

};

std::ostream &print(std::ostream&, const Person&);
std::istream &read(std::istream&, Person&);


#endif
