#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee{
public:
  static int counter;
  Employee(std::string _name) : name(_name) {
    id = counter++;
  }
  Employee(const Employee& e){
    name = e.name;
    id = counter++;
  }
  Employee& operator=(const Employee& e){
    name = e.name;
    id = counter++;
    return *this;
  }
  
  friend void print(const Employee&);
private:
  int id;
  std::string name;
};
int Employee::counter = 0;

#endif
