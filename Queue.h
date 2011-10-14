#ifndef QUEUE_H
#define QUEUE_H

#include <string>

#include "Document.h"
//#include "Linked_List.h"
#include "llp.h"

class Queue
{
 private:
  Linked_List* queue;

 public:
  Queue();
  ~Queue();

  Document* dequeue();
  void      enqueue(Document* document);
  bool      is_empty();
  bool      withdraw(std::string name);

  friend std::ostream& operator<<(std::ostream &os, Queue &in_queue);
};

#endif
