#ifndef STRING_HPP
#define STRING_HPP
#include <scoped_allocator>
#include <iostream>

class String{
  friend void print(String& );
  friend std::ostream& operator<< (std::ostream&, const String&);
  friend bool operator==(const String&, const String&);
  friend bool operator<(const String&, const String&);
public:

  String() : elements(nullptr){};
  String(const char*);
  String(String&&) noexcept;
  String& operator=(const String&);
  ~String();
  size_t size() const { return end - elements; }

private:
  std::allocator<char> alloc;
  void free();
  char* elements;
  char* end;
  std::pair<char*, char*> alloc_n_copy(const char*, const char*);
};

#endif
