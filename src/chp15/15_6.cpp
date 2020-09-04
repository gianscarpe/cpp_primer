class Base{
public:
  virtual int fnc();
};

class D1 : public Base {
public:

  int fcn(int);
  virtual void f2();
};

class D2 : public D1 {
public:
  int fcn(int);
   int fcn() { return D1::fnc(); } 
  //  int fcn() { return D1::fcn(); } D1 doesn't override fcn(), and cannot
  //  offer fcn call in its scope. Must use Base::fcn(), or add using Base into D1
  void f2();
};

void sec15_6(){
  Base bobj; D1 d1obj; D2 d2obj;
  Base *p1 = &bobj,*p2 = &d1obj, *p3= &d2obj;

  p1->fnc();
  p2->fnc(); // base
  p3->fnc(); // D2

  D1 *d1p = &d1obj; D2 *d2p = &d2obj;
  // ERROR:  p2->f2();
  d1p->f2(); // D1
  d2p->f2(); // D2

  d1p->fcn(42); // D1 
  d2p->fcn(42); // D1
}

int main(){

}
  
