#include <string>
#include <vector>
using std::string; using std::vector;

class Account{
public:
  void calculate(){ amount += amount * interest;  }
  static double rate() { return interest; }
  static void rate(double);

private:
  string owner;
  double amount;
  static  double interest;
  static double initRate();
  static constexpr int period = 30;
  double daily_tbl[period]; // period is a constexpr

};



inline void Account::rate(double d) { interest = d; }


// example.h 
class Example { 
public: 
  static double rate; // non const should be initialized outside
  static const int vecSize = 20; 
  static vector<double> vec; // as above
};
double Example::rate = 6.5;
vector<double> Example::vec(Example::vecSize);

int main(){

  double r = Account::rate();

  return 1;
}
