#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <forward_list>
#include <string>

using std::list; using std::vector; using std::cout; using std::endl; using std::forward_list;
using std::string;

void sec9_3_1(){
  list<vector<int>> fit;
  // Error: cannot push 2 elements! fit.push_back(10, 1);
  fit.emplace_back(10, 1); // construct vector of 10 "1" and push it back
  // Equivalent to
  fit.push_back(vector<int>(10, 1));
  // BUT! It does everthing in container dynamic memory (less overhead)
  
}

void ex9_22(){
  vector<int> iv(10, 3);
  int some_val = 3;
  vector<int>::iterator iter = iv.begin(), 
    mid = iv.begin() + iv.size()/2;
  while (iter != mid) {
    if (*iter == some_val)
      iv.insert(iter, 2 * some_val);
    ++iter;
  }
}


void print_vector(vector<int> v){
  for(const auto i : v)
    cout << i << " ";
  cout << endl;
}
void ex9_26(){
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
  vector<int> v(std::begin(ia), std::end(ia));
  list<int> l(std::begin(ia), std::end(ia));

  vector<int>::iterator it = v.begin();
  while(it != v.end()){
    if (*it % 2 == 0)
      v.erase(it);
    ++it;
  }
  print_vector(v);
  

  
}


void sec9_3_3(){
  forward_list<int> l = { 1, 2, 3, 4 };
  auto prev = l.before_begin();
  auto curr = l.begin();
  while (curr != l.end()){
    if ((*curr) % 2 == 1)
      l.erase_after(prev);
    prev = curr;
    /* NOTE: if you use the uncomment version, you get an error! That's because
       after the erasing the successor of prev is the element AFTER curr
       ++prev;
       cout << *prev << endl
    */
    ++curr;
  }

  for(auto i : l){
    cout << i << " ";
  }
  cout << endl;
}

forward_list<string>::iterator insert_after(forward_list<string>& l, string s1,
					    string s2){
  auto prev = l.before_begin();
  auto curr = l.begin();
  while (curr != l.end()){
    if (*curr == s1){ // FOUND!
      curr = l.insert_after(curr, s2);
      return curr;
    }
    prev = curr;
    ++curr;
  }
  curr = l.insert_after(prev, s2);
  return curr;
  
}

void ex9_28(){
  forward_list<string> l = { "asdf", "bb", "ad" };
  auto it = insert_after(l, "bb", "aaa");
  cout << *it << endl;
  assert(*it == "aaa");
  ++it;
  cout << *it << endl;
  assert(*it == "ad");
}

void ex9_29(){
  // silly loop to remove even-valued elements and insert a duplicate of odd-valued elements 
  // ON FORWARD LIST

  forward_list<int> li = {0,1,2,3,4,5,6,7,8,9}; 
  auto it = li.begin(); // call  begin,  not  cbegin  because we're changing vi
  auto prev = li.before_begin();
  
  while (it != li.end()) {
    if (*it % 2) {
      it = li.insert_after(it, *it); // duplicate the current       element
      prev = it;
      it++; // NOTE: it+=2 not allowed on list or forward_LIST
    } else {
      it = li.erase_after(prev);
      prev = it;
    }


  }
  for(auto i : li){
    cout << i << endl;
  }

  // LIST
  list<int> ll = { 0, 1, 2, 3 };
  auto il = ll.begin();
  while (il != ll.end()){
    if (*il % 2){
      il = ll.insert(il, *il);
      il++;
      il++;
    }
    else{
      il = ll.erase(il);
    }

  }

  for(auto i : ll)
    cout << i << endl;
}

void ex9_33(){
  vector<int> v = { 1, 2, 3, 4 };
  auto  begin = v.begin();
  while (begin != v.end()) {
    // do some processing
    ++begin; // advance  begin  because we want to insert after this element
    //begin =
    v.insert(begin, 42);  // insert the new value
    ++begin; // advance  begin  past the element we just added
    // IF we don't reassign begin, ++begin is INVALID
  }
  for(auto i : v)
    cout << i << endl;
}

int main(){
    ex9_22();
    ex9_26();
    sec9_3_3();
    ex9_28();
    ex9_29();
    ex9_33();
  }
