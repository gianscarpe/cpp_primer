#include "String.hpp"
#include <utility>
#include <iostream>
#include <memory>
#include <cstdlib>

using std::pair; using std::cout; using std::endl;
using std::ostream;

pair<char*, char*> String::alloc_n_copy(const char* begin, const char* end){
  auto data = alloc.allocate(end - begin);
  return {data, std::uninitialized_copy(begin, end, data)};
}

void String::free(){
  if (elements){
    cout << "Free" << endl;
    for(auto it = elements; it != end; ++it){
      alloc.destroy(it);
    }
  }
}

String::~String(){
  free();
}

String::String(String&& s) noexcept : elements(s.elements), end(s.end){
  cout << "Move construct" << endl;
  s.elements = s.end = nullptr;
}

String::String(const char *e) {
    cout << "Copy construct" << endl;
    size_t d = 0;
    while (e[d++])
      ;

    auto newdata = alloc_n_copy(e, e + d - 1);
    elements = newdata.first;
    end = newdata.second;
  }

String& String::operator=(const String& rhs){
  cout << "Copy op" << endl;
  auto data = alloc_n_copy(rhs.elements, rhs.end);
  free();
  elements = data.first;
  end = data.second;

  return *this;
}


ostream& operator<< (ostream& os, const String& s){
  for(auto it = s.elements; it != s.end; ++it){
    os << *it;
  }
  return os;
}

bool operator==(const String& s1, const String& s2){
  if (s1.size() != s2.size())    
    return false;
  // I know Andre, I should also compare each element. Btw, it's only an example
  return true;
}
bool operator!=(const String& s1, const String& s2){
  return !(s1 == s2);
}

bool operator<(const String& s1, const String& s2){
  return s1.size() < s2.size();
}

void print(String& s){
  for(auto it = s.elements; it != s.end; ++it){
    cout << *it;
  }
  cout << endl;
}
