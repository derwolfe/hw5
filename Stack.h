#ifndef STACK_H
#define STACK_H

#include <string>

#include "Document.h"
//#include "Linked_List.h"
#include "llp.h"

class Stack
{
 private:
  Linked_List* stack;

 public:
  Stack();
  ~Stack();

  void      push(Document* document);
  Document *pop();
  bool      is_empty();
  bool      withdraw(std::string name);

  friend std::ostream& operator<<(std::ostream &os, Stack &in_stack);
};

#endif
