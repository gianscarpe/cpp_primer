#ifndef STRVEC_HPP
#define STRVEC_HPP
#include <string>
#include <scoped_allocator>

class StrVec{
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {};
  
  StrVec(const StrVec&);
  StrVec& operator=(const StrVec&);
  ~StrVec();

  void push_back(const std::string&);
  void push_back(std::string&&);

  size_t size() {return first_free - elements;}
  size_t capacity() { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }
  std::string &operator[](std::size_t n) const { return elements[n]; }
  const std::string &operator[](std::size_t n) { return elements[n]; }

private:
  std::allocator<std::string> alloc;
  std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
  
  void chk_n_alloc(){
    if (size() == capacity()) reallocate();
  }
  void free();
  void reallocate();
  std::string* elements;
  std::string* first_free;
  std::string* cap;
};


#endif
