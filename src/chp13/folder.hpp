#ifndef FOLDER_HPP
#define FOLDER_HPP
#include "message.hpp"
#include <set>
class Message;
class Folder{
public:
  void addMsg(Message*);
  void removeMsg(Message*);
private:
  std::set<Message *> messages;
};

void Folder::addMsg(Message* m){
  messages.insert(m);
}

void Folder::removeMsg(Message* m){
  messages.erase(m);
}
#endif
