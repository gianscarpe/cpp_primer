#ifndef BLOB_H
#define BLOB_H

#include <memory>
#include <vector>
#include <string>

using std::vector; using std::shared_ptr; using std::string;

class StrBlob{
public:
  typedef std::vector<string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<string> il);
  size_type size() const { return data->size(); }

  bool empty() const { return data->empty(); }
  void push_back(const string &t) {data->push_back(t); }
  void pop_back();
  string& front() const;
  string& back() const;
  string& front();
  string& back();

private:
  shared_ptr<vector<string>> data;
  void check(size_type index, const std::string& msg) const;
};

#endif
