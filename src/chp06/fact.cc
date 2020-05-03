#include <iostream>
#include <vector>
#include "Chapter6.h"


int fact(int n){
  long result = 1;
  while (n > 1)
    result *= n--;
  return result;
}
