#ifndef BLOBPTR_HPP
#define BLOBPTR_HPP

#include <vector>
#include <string>
#include <memory>
#include "Blob.hpp"


template <typename T>
class BlobPtr
{
public:
  BlobPtr() : curr(0) {}
  BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

  T& operator*() const
  {
    auto p = check(curr, "dereference");
    return (*p)[curr];
  }

  BlobPtr& operator++(int);
  BlobPtr& operator--(int);

private:
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
  std::weak_ptr<std::vector<T>> wptr;
  std::size_t curr;
};


template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int){
  BlobPtr ret= *this;
  return ++*this;
}

#endif
