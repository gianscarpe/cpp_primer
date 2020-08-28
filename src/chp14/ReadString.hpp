#ifndef RS_HPP
#define RS_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class ReadString{
public:
  ReadString(const std::string file, char _sep = ' ') : is(std::ifstream(file)), sep(_sep){ };
  std::string operator()(){
    std::string tmp;
    if(is){
      getline(is, tmp);

    }
    return tmp;
  }


private:
  char sep;
  std::ifstream is;
};

#endif
