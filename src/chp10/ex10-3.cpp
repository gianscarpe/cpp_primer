#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int countWords(const std::vector<std::string> words, int &atLeast){
  int count=0;
  atLeast = 5;

  std::for_each(words.begin(), words.end(), [&count, atLeast](std::string w){ if
  (w.length() > atLeast){count++;}});

  
  return count;

}
int main(){

  std::vector<std::string> words{"ciao", "come", "vba"};
  int atLeast = 3;

  const int &referenceToAtLeast = atLeast;

  auto countNWords = std::bind(countWords, std::placeholders::_1, atLeast);
  std::cout << countNWords(words) << std::endl;
  std::cout << atLeast << std::endl;
  std::cout << "Finish";
  return 0;
}
