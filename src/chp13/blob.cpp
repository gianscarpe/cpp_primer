#include "blob.hpp"
#include <exception>
#include <string>
using std::string;

using std::make_shared;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {};

StrBlob::StrBlob(std::initializer_list<string> il)
    : data(make_shared<vector<string>>(il)){};

void StrBlob::check(size_type index, const std::string &msg) const {
  if (index >= data->size())
    throw std::out_of_range(msg);
}

string& StrBlob::front(){
  const StrBlob* ptr = this;
  return ptr->front();
}

string& StrBlob::back(){
  check(0, "empty");
  return data->back();
}

string& StrBlob::front() const {
  check(0, "empty");
  return data->front();
}

string& StrBlob::back() const{
  check(0, "empty");
  return data->back();
}

void StrBlob::pop_back(){
  check(0, "empty");
  data->pop_back();
}
