#include "Queue.h"

using namespace std;

Queue::Queue()
{
  Double_list* queue = new Double_list;
}

Queue::~Queue()
{
  delete queue; 
}

ostream& operator<<(ostream &os, Queue &in_queue)
{
  in_queue.queue->print(os);
  return os;
}

void Queue::enqueue(Document* document)
{
  queue->item_add(document);
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

