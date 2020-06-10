#include <string>
using std::string;

typedef string Type;

Type initVal();
class Ex {
  typedef double Type;
  Type setVal(Type); // Ex::Type setVal(Ex::Type)
  Type initVal(); // Ex::Type 
private:
  int val;
};
Ex::Type Ex::setVal(Type parm){ // Type Ex::setVal(Ex::Type)
  val = parm + initVal();
  return val;
}

  
