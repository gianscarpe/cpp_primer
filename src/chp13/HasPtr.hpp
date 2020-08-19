#ifndef HASPTR_HPP
#define HASPTR_HPP
#include <string>
#include <iostream>
using std::cout; using std::endl;

class HasPtr {
  friend void print(HasPtr&);
  friend void swap(HasPtr&, HasPtr&);
public: 
  HasPtr(const std::string &s = std::string()): 
    ps(new std::string(s)), i(0) { }
  HasPtr(const HasPtr&);
  HasPtr(HasPtr&& p) noexcept : ps(p.ps), i(p.i){
    cout << "Move constructor" << endl;
    p.ps = nullptr;
  }
  ~HasPtr(){
    cout << "Destruction of the object " << ps << endl; 
    delete ps;
  }
  HasPtr& operator=(HasPtr);
  //HasPtr& operator=(const HasPtr&);
  //HasPtr& operator=(HasPtr&&);
private: 
  std::string *ps;
  int i;
};


inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "two HasPtr objects are swapped" << std::endl; // required by exercise 13.30
}

/*
HasPtr& HasPtr::operator=(const HasPtr& p){
  cout << "Copy Assignment" << endl;
  auto newp = new std::string(*p.ps);
  delete ps; // NOTE: free the current memory of this.ps
  ps = newp;
  i = p.i;
  return *this;
}
*/


HasPtr& HasPtr::operator=(HasPtr rhs){
  cout << "Copy and swap" << endl;
  swap(*this, rhs);
  return *this;
}

/*
HasPtr& HasPtr::operator=(HasPtr&& rhs){
  cout << "Move assignment" << endl;
  if (&rhs != this){
    auto newps = rhs.ps;
    ps = newps;
    i = rhs.i;
    rhs.ps = nullptr;
  }

  return *this;
}
*/

HasPtr::HasPtr(const HasPtr& p){
  cout << "Copy constructor" << endl;
  ps = new std::string(*p.ps);
  i = p.i;
  cout << *ps << endl;
}

HasPtr test(HasPtr p){
  return p;
}

#endif

void print(HasPtr& p){
  cout << *p.ps << endl;
}
