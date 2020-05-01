#include <iostream>
#include <cctype>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;


void ex3_2_2(){
  cout << "BEGIN - EX 3.2.2" << endl;
  cout << "Input required!" << endl;
  string input;
  unsigned maxOutputSize = 80;
  while (getline(cin, input)){
    if (input.empty())
      break;

    auto in_size = input.size(); // input.size() has typ string::size_type

    // Note: size is unsigned. Don't use int values for conditional checks
    if (in_size < maxOutputSize)
      cout << input << endl;
  }


  string s1 = "Hello";
  string s2 = "World";
  string s3(10, 'a');
  string s4 = "b";

  // Summation
  string s5 = s1 + " " + s2 + '\n';
  

  /* Compile error:
     string s6 = "Hello" + "World"; // Cannot sum const char[] (alias string literals)
  */

  // FOR loop

 
  assert(s1 < s2);
  assert(s3 < s4);
  assert(s5 == "Hello World\n");

  if (s1.size() == s2.size())
    cout << s1 << " and " << s2 << " has same length" << endl;
    

  
  cout << "ALL PASSED! END - EX 3.2.2" << endl;  
  
}

void ex3_2(){
  string s1; // default initialization; s1 is the empty string
  string s2 = s1; // copy; compiler understand the intended semantics
  string s2Alternative(s1); // direct copy initialization
  string s3 = "af"; // copy of string literal
  string s4(20, 'c'); // repeat charcater n times

  cout << "This is strange! " << s4 << endl;
}


void ex3_2_3(){
  cout << "BEGIN - EX 3.2.3" << endl;
  string input = "Hello!!!"; // 3 puntcs

  decltype(input.size()) count_punct = 0;
  for (auto c : input){
    if (ispunct(c))
      ++count_punct;
  }
  assert(count_punct == 3);

  string lower_string = "hello";
  for (auto &c : lower_string){
    c = toupper(c);
  }
  string capitalize_first_word = "hello world";
  for (decltype(capitalize_first_word.size()) index = 0; index !=
	 capitalize_first_word.size() && !isspace(capitalize_first_word[index]);
       index++)
    capitalize_first_word[index] = toupper(capitalize_first_word[index]);


  const string hexadigits = "0123456789ABCDEF";
  cout << "Enter your digits!";
  string result = "";
  decltype(hexadigits.size()) n = 0;
  while(cin >> n){
    if (n < hexadigits.size())
      result += hexadigits[n];
  }
  cout << "Your number in hexadecimal: " << result << endl;
  
  assert(capitalize_first_word == "HELLO world");
  assert(lower_string == "HELLO");

  cout << "ALL PASSED! END - EX 3.2.3" << endl;  
}

void ex3_6(){
  cout << "BEGIN EX 3.6" << endl;
  string input = "Hello world!";
  string output = input;
  for(decltype(output.size()) i = 0; i != output.size(); i++){
    output[i] = 'X';
  }

  assert(output == "XXXXXXXXXXXX");
  cout << "ALL PASSED! END - EX 3.6" << endl;  
}

void ex3_7(){
  cout << "BEGIN EX 3.7" << endl;
  string input = "Hello world!";
  string output = input;
  for(decltype(output.size()) i = 0; i != output.size(); i++){
    output[i] = 'X';
  }
  
  assert(output == "XXXXXXXXXXXX");
  cout << "ALL PASSED! END - EX 3.7" << endl;  
}

void ex3_8(){
  cout << "BEGIN EX 3.8" << endl;
  
  string input = "Hello world!";
  string output = input;
  decltype(output.size()) i = 0;
  while(i != output.size()){
    output[i] = 'X';
    ++i;
  }
  
  assert(output == "XXXXXXXXXXXX");
  cout << "ALL PASSED! END - EX 3.8" << endl;  
}

void ex3_9(){
  cout << "BEGIN EX 3.9" << endl;
  string s;

  cout << s[0] << endl;
  cout << "ALL PASSED! END - EX 3.9" << endl;  
}

void ex3_10(){
  cout << "BEGIN EX 3.10" << endl;
  string input;
  string output = "";
  getline(cin, input);

  for(auto c : input){
    if (!ispunct(c))
      output+=c;
  }
  cout << "Your phrase without punct: " << output << endl;

  cout << "END EX 3.10" << endl;
  

}

void ex3_11(){
  const string input = "test";
  for(const char &c : input){
    /* Compile error!
       c = 'a';
     */
    cout << c;
    
  }
}

int main(){
  ex3_2();
  // ex3_2_2();
  //ex3_2_3();
  ex3_6();
  ex3_7();
  ex3_8();
  ex3_9();
  //ex3_10();

  return 1;
}
