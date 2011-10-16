#include "Queue.h"

using namespace std;
/* for some reason, it is seg faulting on all operations that require the size
 * variable local to the double list. I am unsure of why.
 */
Queue::Queue()
{
  queue = new Double_list();
//  cout << queue->get_length() << endl;
}

Queue::~Queue()
{
//  delete queue; 
}

ostream& operator<<(ostream &os, Queue &in_queue)
{
  in_queue.queue->print(os);
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
