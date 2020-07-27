#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using std::set; using std::map; using std::cout; using std::endl;
using std::string; using std::cin;

void lower_string(string& s){
  for(auto& c : s)
    c = tolower(c);
}

void remove_punct_and_lower(string& word){
  lower_string(word);
  auto end_curr = std::stable_partition(word.begin(), word.end(),
                                        [](char c) { return !ispunct(c); });

  word.erase(end_curr, word.end());

  
 }

void ex11_4(){
  set<string> exclude = { "the", "a", "an" };

  map<string, int> count;
  string word;
  while (cin >> word){
    cout << "input " << word << endl;
    remove_punct_and_lower(word);	
    cout << "No punct " << word << endl;
    if (exclude.find(word) == exclude.end())
      ++count[word];
  }
  for(auto s: count)
    cout << s.first << " " << s.second << endl;
}

int main(){
  ex11_4();
  return 1;
}
