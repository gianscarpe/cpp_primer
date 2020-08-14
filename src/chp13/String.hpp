#ifndef STRING_HPP
#define STRING_HPP
#include <scoped_allocator>

class String{
public:
  friend void print(String);
  String() : elements(nullptr){};
  String(const char*);
  String& operator=(const String&);
  ~String();
private:
  std::allocator<char> alloc;
  void free();
  char* elements;
  char* end;
  std::pair<char*, char*> alloc_n_copy(const char*, const char*);
};

#endif
