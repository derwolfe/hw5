#include "Queue.h"

/* 
 * Functions as a wrapper for all list functions
 */
using namespace std;

Queue::Queue()
{
  queue = new Double_list();
}

Queue::~Queue()
{
  delete queue; 
}

/* 
 * This is needed to read the list backwards.
 */
ostream& operator<<(ostream &os, Queue &in_queue)
{
  in_queue.queue->print_back(os);
  return os;
}

void Queue::enqueue(Document* document)
{
  queue->doc_add(document);
}

Document* Queue::dequeue()
{
  queue->dequeue();
}

bool Queue::is_empty()
{
  return queue->is_empty();
}

bool Queue::withdraw(std::string name)
{
  queue->remove(name);
}

Document* Queue::peek(std::string name)
{
  return queue->retrieve(name);
}
