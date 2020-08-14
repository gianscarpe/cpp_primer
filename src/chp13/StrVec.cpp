#include "StrVec.hpp"
#include <string>
#include <utility>
#include <iostream>

using std::string; using std::pair; using std::cout; using std::endl;


void StrVec::push_back(const string& s){
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* begin, const string*
end){
  auto data = alloc.allocate(end - begin);
  return {data, uninitialized_copy(begin, end, data)};
}

void StrVec::free(){
  if (elements) {
    cout << "Freeing" << endl;
    std::for_each(elements, cap, [this](string& p){
					  alloc.destroy(&p);});

    alloc.deallocate(elements, cap - elements);
  }
  
}

StrVec::StrVec(const StrVec& s){
  cout << "Copy" << endl;
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}


StrVec& StrVec::operator=(const StrVec& s){
  cout << "Operator" << endl;
  auto newdata = alloc_n_copy(s.begin(), s.end());
  free();

  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}
StrVec::~StrVec(){
  free();
}

void StrVec::reallocate(){
  cout << "Current capacity" << capacity() << endl;;
  auto newcap = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcap);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));

  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcap;
  cout << "New capacity" << capacity() << endl;;
}
