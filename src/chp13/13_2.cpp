#include <iostream>
#include <string>
using std::string;

class HasPtr { 
public: 
  // constructor allocates a new  string  and a new counter, which it sets to  1
  HasPtr(const std::string &s = std::string()): 
    ps(new std::string(s)), i(0), use(new std::size_t(1)) {} 
  // copy constructor copies all three data members and increments the counter
  HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) { ++*use; }
  HasPtr& operator=(const HasPtr&); 
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

HasPtr& HasPtr::operator=(const HasPtr& rhs){
  ++*use;
  if (--*use == 0){
    delete ps;
    delete use;
  }

  ps = rhs.ps;
  i = rhs.i;
  use = rhs.use;
   
  return *this;
}

class TreeNode{
public:
  TreeNode(string _value, int _count) : value(_value), count(_count) {}
  TreeNode(const TreeNode &p)
      : value(p.value), count(p.count), left(p.left), right(p.right) {}

private:
  string value;
  int count;
  TreeNode *left;
  TreeNode *right;
  
};
