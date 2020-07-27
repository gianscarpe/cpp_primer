#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using std::cin; using std::cout; using std::endl; using std::map; using std::string;
using std::set;

void sec11_3_2(){
  map<string, size_t> count;
  string word;
  while( cin >> word){
    auto ret = count.insert(std::make_pair(word, 1));
    if (!ret.second)
      ++ret.first->second;
    

  };
  for(auto p : count)
    cout << p.first << ": " << p.second << endl;;

}

void sec11_3_5() {
  string search = "E. Poe";
  std::multimap<string, string> authors = {
					   {"E. Poe", "Test"},
					   {"G. Scarpellini", "Aaa"},
					   {"E. Poe", "The sorrow"}
  };
    
  auto lower = authors.lower_bound(search);
  auto upper = authors.upper_bound(search);

  while (lower != upper){
    cout << lower->second << endl;
    ++lower;
  }

  cout << "Using range_equal" << endl;
  for(auto pair = authors.equal_range(search); pair.first != pair.second;
      ++pair.first){
    cout << pair.first->second << endl;

  }
  
}

void ex11_32(){
  std::multimap<string, string> authors = {
					   {"E. Poe", "Test"},
					   {"G. Scarpellini", "Bbb"},
					   {"G. Scarpellini", "Aaa"},
					   {"E. Poe", "The sorrow"},
					   {"A. Aaa", "Allah"}};

  set<string> found;
  string author;
  for(auto it = authors.cbegin(); it != authors.cend(); ++it){
    author = it->first;
    if(found.find(author) == found.end()){
      cout << "Author: " << author << endl;
      
      auto pair = authors.equal_range(author);
      set<string> entries;
      for (; pair.first != pair.second;
	   ++pair.first) 
	entries.insert(pair.first->second);

      for(string w : entries)
	cout << w << endl;
      found.insert(author);
    }
  }

}

void ex11_32b(){
  std::multimap<string, string> authors{
					{ "alan", "DMA" },
					{ "pezy", "LeetCode" },
					{ "alan", "CLRS" },
					{ "wang", "FTP" },
					{ "pezy", "CP5" },
					{ "wang", "CPP-Concurrency" }
  };
  std::map<string, std::multiset<string>> order_authors;
  for (const auto &author : authors)
    order_authors[author.first].insert(author.second);
  for (const auto &author : order_authors) {
    std::cout << author.first << ": ";
    for (const auto &work : author.second)
      std::cout << work << " ";
    std::cout << std::endl;
  }
}

map<string, string> get_map(std::istream& in){
  map<string, string> transf;
  string key;
  string phrase;
y
  while(in >> key){
    getline(in, phrase);
    transf[key] = phrase.substr(1);
  }

  return transf;
}

string apply_to_phrase(map<string, string> &transf, string phrase){
  std::stringstream in(phrase);

  string word;
  string result("");
  while(in >> word){
    if (transf.find(word) != transf.end())
      word = transf[word];
    result += word + " ";
  }
  return result;
}

void apply_map(map<string, string> &transf, std::istream& file, std::ostream& out){
  string input_phrase;
  while(getline(file, input_phrase)){
    out << apply_to_phrase(transf, input_phrase);
  }
}

void sec11_3_6(){
  map<string, string> transf = get_map(cin);  
  for(auto s : transf)
    cout << s.first << ": " << s.second << endl;


  string input_file = "input.txt";
  std::ifstream in(input_file);
  std::ofstream out("out.txt");
  
  apply_map(transf, in, out);
}

int main(){
  //    sec11_3_2();
  //sec11_3_5();
  //  ex11_32();
  sec11_3_6();
  
  return 1;
}
