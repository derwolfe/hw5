#include "Stack.h"

using namespace std;

Stack::Stack()
{
  stack = new Double_list;
}

Stack::~Stack()
{
  delete stack;
}

ostream& operator<<(ostream &os, Stack &in_stack)
{
  in_stack.stack->print(os);

  return os;
}

void Stack::push(Document* document)
{
  stack->doc_add(document);
}

Document* Stack::pop()
{
  stack->pop();
}

bool Stack::is_empty()
{
  stack->is_empty();
}

bool Stack::withdraw(std::string name)
{
  stack->remove(name);
}
/* 
 * Peek an item - useful for retrieve remove. Could have been implemented in
 * remove. But, I would prefer to check first outside of the remove function.
 */
Document* Stack::peek(std::string name)
{
  return stack->retrieve(name);
}

