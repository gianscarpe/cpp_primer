#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

void sec3_4_1(){
  cout << "Begin sec 3.4.1" << endl;
  vector<int> v{1, 2, 3, 4, 5};
  for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
  cout << endl;
    

  for(auto it = v.cbegin(); it != v.cend(); ++it){
    /* Compile error: operator return const value
     *it = 42;
     */
  }

  for(auto it = v.cend()-1; it != v.begin()-1; --it){
    cout << *it << " ";
  }
  cout << endl;

  // Better use rbegin and rend()
  for(auto it = v.rbegin(); it != v.rend(); it++){
    cout << *it << " ";
  }
  cout << endl;

  vector<string> text{"hello", "I", "love", "", "you"};

  for(auto it = text.cbegin(); it != text.cend() and !(*it).empty(); ++it){
    cout << *it << " ";
  }
  cout << endl;

  // Alternative version (more readble)
  
  for(auto it = text.cbegin(); it != text.cend() and !it->empty(); ++it){
    cout << *it << " ";
  }
  cout << endl;

  
  cout << "End sec 3.4.1" << endl;
}

void ex3_22(){
  cout << "Begin ex 3.22" << endl;
  vector<string> text{"Hello", "I", "love", ".", "You", "are", "crazy"};
  
  for(auto it = text.begin(); it != text.end() and !ispunct(*(it->end()-1));
      ++it){
    for(auto it_word = it->begin(); it_word != it->end(); ++it_word)
      *it_word = toupper(*it_word);
  }

  cout << "To uppercase: " << endl;
  for (auto it = text.cbegin(); it != text.cend(); ++it)
    cout << *it << " ";

  cout << "End ex 3.22" << endl;

}

void ex3_23(){
  cout << "Begin ex 3.23" << endl;
  vector<int> elements{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for(auto it = elements.begin(); it != elements.end(); ++it)
    *it = *it * 2;

  for(auto it = elements.cbegin(); it != elements.cend(); ++it)
    cout << *it << " ";
  cout << endl;
  cout << "End ex 3.23" << endl;
}

void sec3_4_2(){
  cout << "Begin ex 3.4.2 -- Binary search in text" << endl;
  vector<string> text { "hello", "i", "love", "you" };
  std::sort(text.begin(), text.end());

  string input;
  cout << "Your word:";
  cin >> input;

  auto beg=text.cbegin(), end=text.cend();
  //auto mid = beg + (end - beg) / 2;
  auto mid = beg + text.size() / 2;
  
  bool found = false;

  while(!found and beg < end){
    if (*mid == input)
      found=true;
    else if (*mid > input){
      end = mid;
      mid = beg + (end - beg) / 2;
      
    }
    else{
      beg = mid;
      mid = beg + (end - beg) / 2;
    }
  }

  cout << "Found:" << found << endl;
}

void ex3_25(){
  cout << "Begin ex 3.25" << endl;
  vector<unsigned> grades;
  vector<unsigned> clusters(11, 0);
  unsigned input;
  while (cin >> input)
    grades.push_back(input);


  for (auto it = grades.cbegin(); it != grades.cend(); ++it) {
    cout << *it << endl;
    if ((*it) <= 100)
      clusters[(*it) / 10]+=1;
  }
  for(auto it = clusters.cbegin(); it != clusters.cend(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << "End ex 3.25" << endl;
  
}

int main() {
    sec3_4_1();
    ex3_22();
    ex3_23();
    //sec3_4_2();
    ex3_25();

    return 1;
}

