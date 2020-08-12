#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "message.hpp"

using std::string; using std::cin; using std::cout; using std::endl;
using std::vector;

class HasPtr { 
public:
  friend void swap (HasPtr&, HasPtr&);
  friend void print(const HasPtr&);
  // constructor allocates a new  string  and a new counter, which it sets to  1
  HasPtr(const std::string &s = std::string()): 
    ps(new std::string(s)), i(0), use(new std::size_t(1)) {} 
  // copy constructor copies all three data members and increments the counter
  HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) { ++*use; }
  HasPtr& operator=(HasPtr);
  bool operator<(const HasPtr&) const; 
  ~HasPtr(); 
private: 
  std::string *ps;
  int i;
  std::size_t *use; 
};

HasPtr::~HasPtr(){
  if (--*use == 1){
    delete ps;
    delete use;
  }
}


HasPtr& HasPtr::operator=(HasPtr rhs){
  swap(*this, rhs);
  return *this;
}
bool HasPtr::operator<(const HasPtr& rhs) const {
  return *(this->ps) < *(rhs.ps);
}

inline
void swap(HasPtr& lhs, HasPtr& rhs){
  using std::swap;
  cout << "Swapping" << endl;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  swap(lhs.use, rhs.use);

}

inline
void print(const HasPtr& p){
  cout << p.i << " " << *p.ps << " " << endl;
}


void sec_13_3(){
  HasPtr p1("Hi"), p2("How"), p3("Ciao");
  vector<HasPtr> v { p1, p2, p3 };
  std::sort(v.begin(), v.end());
  for(auto p : v)
    print(p);
  
}


void sec_13_email(){
  Folder spam;
  Message m1("Ciao"), m2("Hi");
  m1.save(spam);
  
}

int main(){
  sec_13_3();
  sec_13_email();
}
