#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string; using std::cin; using std::cout; using std::endl; using std::vector;

void elimDups(vector<string> v){
  std::sort(v.begin(), v.end());
  auto curr = std::unique(v.begin(), v.end());
  v.erase(curr, v.end());
  
}

bool is_shorter(string s1, string s2){
  return s1.size() < s2.size();
  
}
void sec10_3_2(){
  vector<string> v = {"SASDF", "asdf", "abbb", "bbb", "ccc", "adfev", "cdd",
		      "ddcddd", "asdf"};
  elimDups(v);
  std::stable_sort(v.begin(), v.end(), is_shorter);

  // LAMBDA
  string::size_type min_length = 3;
  auto predicate = [min_length](const string& s) -> bool {
		     return s.size() >= min_length;
      };
  auto it = std::find_if(v.begin(), v.end(), predicate);
  auto wc = v.end() - it;
  cout << "Words with size at least " << min_length << " are: " << wc << endl;
}

void ex_10_18(){
  vector<string> v = {"SASDF", "asdf", "abbb", "bbb", "ccc", "adfev", "cdd",
		      "ddcddd", "asdf"};
  elimDups(v);
  std::stable_sort(v.begin(), v.end(), is_shorter);

  // LAMBDA
  string::size_type min_length = 5;
  auto predicate = [min_length](const string &s) -> bool {
    return s.size() >= min_length;
  };
  
  auto it = std::partition(v.begin(), v.end(), predicate);
  cout << "First word NOT respecting " << *it << endl;
  auto wc = it - v.begin();
  cout << "Words with size at least " << min_length << " are: " << wc << endl;
}

void ex_10_20(){
  vector<string> v = {"SASDF", "asdf", "abbb", "bbb", "ccc", "adfev", "cdd",
		      "ddcddd", "asdf"};
  elimDups(v);
  std::stable_sort(v.begin(), v.end(), is_shorter);

  // LAMBDA
  string::size_type min_length = 5;
  auto predicate = [min_length](const string &s) -> bool {
    return s.size() >= min_length;
  };
  
  auto it = std::partition(v.begin(), v.end(), predicate);
  cout << "First word NOT respecting " << *it << endl;
  auto wc = std::count_if(v.begin(), v.end(), predicate);
  cout << "Words with size at least " << min_length << " are: " << wc << endl;
}

void ex_10_21(){
  int i = 10;

  // Mutable: change the internal value of i, not outside
  auto f_mutable = [i]() mutable {
    if (i > 0) {
      --i;
      return true;
    }
    else
      return false;
	   };

  // By reference: change the external value of i
    auto f_reference = [&i]() mutable {
    if (i > 0) {
      --i;
      return true;
    }
    else
      return false;
	   };
    
  while(f_mutable())
    cout << i << endl;

  i = 10;
  while(f_reference())
    cout << i << endl;
}


int main(){
  sec10_3_2();
  ex_10_18();
  ex_10_20();
  ex_10_21();
  return 1;
}
