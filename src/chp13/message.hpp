#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <set>
#include "folder.hpp"

class Message { 
  friend class Folder; 
public: 
  // folders  is implicitly initialized to the empty  set
  explicit Message(const std::string &str = "") : contents(str) {}
  // copy control to manage pointers to this  Message
  Message(const Message&);
  ~Message();
  Message& operator=(const Message&);
  Message& operator=(Message&&);
  
  // add/remove this  Message  from the specified  Folder's set of messages
  void save(Folder&);
  void remove(Folder &);
  friend void swap(Message& lhs, Message& rhs);

private:
  std::string contents;
  std::set<Folder *> folders; // Folders that have this  Message // utility functions used by
  // copy constructor, assignment, and destructor // add this
  // Message  to the  Folders that point to the parameter
  void add_to_Folders(const Message &);
  // remove this  Message  from every  Folder  in  folders
  void remove_from_Folders();

  // move m.folders to this
  void move_Folders(Message*);
};

void Message::save(Folder& folder){
  folders.insert(&folder);
  folder.addMsg(this);

  
}

void Message::remove(Folder& folder){
  folders.erase(&folder);
  folder.removeMsg(this);
  
}

void Message::add_to_Folders(const Message& m){
  for(auto f : m.folders)
    f->addMsg(this);
}

void Message::remove_from_Folders(){
  for (auto f : folders)
    f->removeMsg(this);
}

void Message::move_Folders(Message* m){
  folders = std::move(m->folders);
  for(auto f : folders){
    f->removeMsg(m);
    f->addMsg(this);
  }
  m->folders.clear();
}



Message::Message(const Message& m) : contents(m.contents), folders(m.folders){
  add_to_Folders(m);
}

Message::~Message(){
  remove_from_Folders();
}

Message& Message::operator=(const Message& rhs){
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

Message& Message::operator=(Message&& rhs){
  if (&rhs != this){
    remove_from_Folders();
    contents = std::move(rhs.contents);
    move_Folders(&rhs);
  }
  return *this;
}

inline
void swap(Message& lhs, Message& rhs){
  using std::swap;

  lhs.remove_from_Folders();
  rhs.remove_from_Folders();
  
  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);

  lhs.add_to_Folders(lhs);
  rhs.add_to_Folders(rhs);
  

}

#endif
