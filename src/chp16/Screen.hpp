#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>
#include <iostream>


template<int width, int height> class Screen;
template<int width, int height> std::ostream& operator<<(std::ostream&, const Screen<width, height>&);
template<int width, int height>  std::istream& operator>>(std::istream&, Screen<width, height>&);

template<int width, int height> class Screen{
  friend std::istream& operator>> <width, height>(std::istream&, Screen<width, height>&);
  friend std::ostream& operator<< <width, height>(std::ostream&, const Screen<width, height>&);
public:
  Screen() : data(height*width, ' '), cur(0) {}
  void display() const;
private:
  std::string data;
  int cur;
};


template<int width, int height>
std::istream& operator>>(std::istream &is, Screen<width, height> &s){
  std::string input;
  getline(is, input);
  s.data = input;
  s.cur = input.size();
  return is;
}

template<int width, int height>
std::ostream& operator<<(std::ostream& os, const Screen<width, height> &s){
  for(int c = 0; c != s.cur; ++c){
    os << s.data[c];
    if ((c+1) % width == 0)      
      os << std::endl;
  }
  return os;
}


#endif
