#include "Screen.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::string; using std::vector;
using std::cin; using std::cout; using std::endl;


void Screen::do_display(std::ostream &out) const{
  for(pos c = 0; c != contents.length(); ++c){
    out << contents[c];
    if ( (c+1) % width == 0)
      out << endl;
  }
  out << endl;
}

char Screen::get(pos ht, pos wd) const{
  counter++; // note: can be modified because is MUTABLE
  return contents[width * ht + wd];
}

Screen &Screen::move(pos r, pos c){
  cursor = r * width + c;
  return *this;
}

Screen &Screen::set(char c){
  contents[cursor] = c;
  return *this;
}

Screen &Screen::set(pos r, pos col, char ch){
  contents[r * height + col] = ch;
  return *this;
}

void Window_mgr::clear(ScreenIndex index){
  Screen &s = screens[index];
  s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& newScreen){
  screens.push_back(newScreen);
  return screens.size() - 1;
}
