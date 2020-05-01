#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using kernel = int[3][3];

void print_matrix(kernel (&ia)){
  for(auto& i : ia) // Note: i is a reference to a pointer
    {
      for(auto& j : i)
	cout << j << " ";
      cout << endl;
    }


}

void sec3_6_1(){
  cout << "Begin sec 3.6" << endl;

  int ia[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  print_matrix(ia);
  
  kernel ia2 =
    { {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    };
  print_matrix(ia2);

  int (&row)[3] = ia[0];
  for(auto& i : row)
    i = 0;

  for(size_t i = 0; i < 3; i++)
    assert(ia[0][i] == 0);


  cout << "End sec 3.6" << endl;

}

void ex3_43(){
  int m[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  
  // First version
  for(int (*p)[3] = std::begin(m); p != std::end(m); p++)
    {
      for(int *q = *p; q != std::end(*p); q++)
	cout << *q << " ";
      cout << endl;
    }

  // Second version
  for(int (&p)[3] : m){
    for (int q : p)
      cout << q << " ";
    cout << endl;
  }
    
}

int main() {
  sec3_6_1();
  ex3_43();
  return 1;
}
