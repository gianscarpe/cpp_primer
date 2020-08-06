#include <string>
#include <iostream>
#include "employee.hpp"

using std::string; using std::cin; using std::cout; using std::endl;


class HasPtr { 

public: 
  HasPtr(const std::string &s = std::string()): 
    ps(new std::string(s)), i(0) { }
  HasPtr(const HasPtr&);
  ~HasPtr(){
    cout << "Destruction of the object: " << *ps << endl;
    delete ps;

  }
  
  HasPtr& operator=(const HasPtr&);
private: 
  std::string *ps;
  int i;
};
HasPtr& HasPtr::operator=(const HasPtr& p){
  cout << "Copy Assignment" << endl;
  auto newp = new std::string(*p.ps);
  delete ps; // NOTE: free the current memory of this.ps
  ps = newp;
  i = p.i;
  return *this;
}
  
HasPtr::HasPtr(const HasPtr& p){
  cout << "Copy constructor" << endl;
  ps = new std::string(*p.ps);
  i = p.i;
  cout << *ps << endl;
}

HasPtr test(HasPtr p){
  return p;
}


class Numbered{
public:
  Numbered() : mysn(rand() % 100) {}
  Numbered(const Numbered&);
  Numbered& operator=(const Numbered&);
  friend void print(const Numbered&);
private:
  int mysn;
};
Numbered::Numbered(const Numbered& n){
  mysn = rand() % 100;
}

Numbered& Numbered::operator=(const Numbered& n){
  mysn = rand() % 100;
  return *this;
}

void print(const Numbered& p){
  cout << p.mysn << endl;
}

void ex13_5(){
  HasPtr p("hello");
  HasPtr p2 = p;
  HasPtr p3 = test(p2);
  p3 = p;
}

void ex13_14(){
  Numbered a, c;
  Numbered b = a;
  c = b;
  print(a);
  print(b);
  print(c);
}

void print(const Employee& e){
  cout << e.id << " " << e.name << endl;
}

void ex13_18(){
  Employee e1("Gian"), e2("Pip"), e3("T");
  e3 = e1;
  Employee e4(e3);
  print(e1);
  print(e2);
  print(e3);
  print(e4);
}

int main(){
  ex13_5();
  ex13_14();
  ex13_18();
}
