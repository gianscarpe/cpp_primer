#include "StrVec.hpp"
#include <string>

using std::string; using std::pair;

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
    for (auto p = first_free; p != elements;)
      alloc.destroy(--p);

    alloc.deallocate(elements, cap - elements);
  }
  
}

StrVec::StrVec(const StrVec& s){
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}


StrVec& StrVec::operator=(const StrVec& s){
  auto newdata = alloc_n_copy(s.begin(), s.end());
  free();

  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}
StrVec::~StrVec(){
  free();
}
