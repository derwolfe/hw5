#ifndef STACK_H
#define STACK_H

#include <string>

#include "Document.h"
#include "llp.h"

class Stack
{
 private:
  Double_list* stack;

 public:
  Stack();
  ~Stack();

  void      push(Document* document);
  Document* pop();
  bool      is_empty();
  bool      withdraw(std::string name);
  Document* peek(std::string name);

  friend std::ostream& operator<<(std::ostream &os, Stack &in_stack);
};

#endif
