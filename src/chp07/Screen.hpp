#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include <iostream>

using std::string; using std::vector;
using std::cin; using std::cout; using std::endl;

class Screen;

class Window_mgr {
public:
  typedef std::vector<Screen>::size_type ScreenIndex;
  void clear(ScreenIndex);
  ScreenIndex addScreen(const Screen&);
  Window_mgr() = default;
  
private:
  vector<Screen> screens; //{ Screen(24, 80, ' ') };

};

class Screen{
  friend class Window_mgr; // entire class as friend
  friend void Window_mgr::clear(ScreenIndex); // only member; must be declared
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {};
  Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {};
  char get() const {
    return contents[cursor];
  }
  char get(pos ht, pos wd) const;
  Screen &set(pos ht, pos wd, char c);
  Screen &set(char cr);
  Screen &move(pos r, pos c);
  Screen &display(std::ostream &out) { do_display(out); return *this; };
  pos size() const { return height * width; };
  const Screen &display(std::ostream & out) const {
    do_display(out);
    return *this;
  };

private:
  mutable size_t counter=0;
  pos cursor =0;
  pos height=0, width=0;
  std::string contents;
  void do_display(std::ostream&) const; // Display implementation
};


#endif
