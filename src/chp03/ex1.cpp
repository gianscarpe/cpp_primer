#include <string>
#include <iostream>

using std::string;

int operator<(string s1, string s2)
{
  if (s1 == "C++")
    return 1;
  else
    return s1 < s2;
}

int main(){

  string s1, s2;
  std::cin >> s1 >> s2;

  string result = (s1 < s2) ? s1 : s2;
  std::cout <<  "Who is better? " << result << std::endl;
  
  
  

}
