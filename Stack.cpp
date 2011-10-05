#include "Stack.h"

using namespace std;

Stack::Stack()
{

}

Stack::~Stack()
{

}

ostream& operator<<(ostream &os, Stack &in_stack)
{
  in_stack.stack->print(os);

  return os;
}

void Stack::push(Document* document)
{

}

Document* Stack::pop()
{

}

bool Stack::is_empty()
{

}

bool Stack::withdraw(std::string name)
{

}


