#include "Queue.h"

using namespace std;

Queue::Queue()
{

}

Queue::~Queue()
{

}

ostream& operator<<(ostream &os, Queue &in_queue)
{
  in_queue.queue->print(os);

  return os;
}

void Queue::enqueue(Document* document)
{

}

Document* Queue::dequeue()
{

}

bool Queue::is_empty()
{

}

bool Queue::withdraw(std::string name)
{

}



