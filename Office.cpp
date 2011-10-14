#include "Office.h"

using namespace std;

/*
 * Constructor and destructor. Note that each element created with a
 * "new" statement in the constructor has a corresponding "delete"
 * statement in the destructor.
 */
Office::Office()
{
  Stack *inbox_stack = new Stack;
  Queue *priority_queue_one = new Queue;
  Queue *priority_queue_two = new Queue;
  Queue *priority_queue_three = new Queue;
  
  in_office = false;
  read_count = 0;
  Document* current_document = NULL;
}

/* what all needs to be deconstructed and deallocated? anything with new, kill
 */
Office::~Office()
{
  delete inbox_stack;
  delete priority_queue_one;
  delete priority_queue_two;
  delete priority_queue_three;

  in_office = false;
  read_count = 0;
  Document* current_document = NULL;
}

/*
 * Overloaded output operator for the Office class. Do not change this
 * code, as it will change the output format, making the use of "diff"
 * in the makefile to check correctness impossible.
 */
ostream& operator<<(std::ostream &os, Office &office)
{
  os << "-------------------------" << endl;
  os << "| CURRENT OFFICE STATUS |" << endl;
  os << "-------------------------" << endl;

  /*
   * Worker state
   */
  if (office.in_office) {
    if (office.current_document != NULL)  {
      os << "READER : READING ";
      os << (*office.current_document).get_name() << endl;
    } else {
      os << "READER : IDLE" << endl;
    }
  } else {
      os << "READER : ABSENT" << endl;
  }

  /*
   * In-box state
   */
  if (!office.inbox_stack->is_empty()) {
    os << "INBOX  : ";
    os << *office.inbox_stack;
    os << "<-TOP" << endl;
  } else {
    os << "INBOX  : EMPTY" << endl;
  }

  /*
   * Now, each queue, in priority order
   */
  if (!office.priority_queue_one->is_empty()) {
    os << "QUEUE 1: ";
    os << *office.priority_queue_one;
    os << "<-FRONT" << endl;
  } else {
    os << "QUEUE 1: EMPTY" << endl;
  }

  if (!office.priority_queue_two->is_empty()) {
    os << "QUEUE 2: ";
    os << *office.priority_queue_two;
    os << "<- FRONT" << endl;
  } else {
    os << "QUEUE 2: EMPTY" << endl;
  }

  if (!office.priority_queue_three->is_empty()) {
    os << "QUEUE 3: ";
    os << *office.priority_queue_three;
    os << "<- FRONT" << endl;
  } else {
    os << "QUEUE 2: EMPTY" << endl;
  }

  return os;
}

/*
 * Worker Bee enters and leaves the office 
 */
void Office::enter()
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   */
    cout << "Error: someone is already in the office" << endl;
    cout << "You cannot enter until he leaves" << endl;
}

void Office::leave()
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   */
    cout << "Error: there is nobody in the office to leave" << endl;
}

int Office::get_read_count()
{
  return read_count;
}

/* takes the info from fin, parses, shoots here. Then it uses
 * the native linked list push function.
 */
void Office::submit_document(string name, string priority)
{
  
  inbox_stack->push(name, priority);
}

/* 
 *  Read the highest priority document from the available queue.
 *  if queue 1 has docs, read them, if not, q2, if not, q3, if not no docs!
 */
void Office::read_document()
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   *
   * Go through each of the queues, if one is empty move on to the next.
   */
      cout << "No more documents to read" << endl;

      cout << "READER : START " << current_document->get_name() 
           << endl << endl;

    cout << "Error: cannot read when nobody is in the office" << endl;

}

void Office::sort_inbox()
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   *
   * for each of the documents in the stack, beginning with the top, 
   * pop it off of the stack, and enqueue it based on priority
   */
  int inc = inbox_stack->get_length();
  while (inc >= 0) {
   Document* target  = inbox_stack->pop();
   if (target->get_priority() == PRIORITY_1) {
      priority_queue_one->enqueue(target);
    } else if (target->get_priority() == PRIORITY_2) {
      priority_queue_two->enqueue(target);
    } else if (target->get_priority() == PRIORITY_3) {
      priority_queue_three->enqueue(target);
    } else {
      cout << "Error: bad priority on document:" << cur << endl;
    }
  }
}
  

void Office::withdraw_document(string name)
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   *
   * Each of these statements is meant to try to find the document in the
   * stack, if it does, it should remove it from the stack, otherwise, check the
   * next stack.
   */
  Document* target = inbox_stack->retrieve(name);
  if (target == NULL) {
    continue;
  } else { 
    inbox_stack->remove(name);
    cout << "Document " << name << " removed from inbox" << endl;
    target = NULL;
    break;
  }
  
  Document* target = priority_queue_one->retrieve(name);
  if (target == NULL) {
    continue;
  } else { 
    priority_queue_one->remove(name);
    cout << "Document " << name << " removed from queue 1" << endl;
    target = NULL;
    break;
  }

  Document* target = priority_queue_two->retrieve(name);
  if (target == NULL) {
    continue;
  } else {
    priority_queue_two->remove(name);
    cout << "Document " << name << " removed from queue 2" << endl;
    target = NULL;
    break;
  }

  Document* target = priority_queue_three->retrieve(name);
  if (target == NULL) {
    continue;
  } else { 
    priority_queue_three->remove(name);
    cout << "Document " << name << " removed from queue 3" << endl;
    target = NULL;
    break;
  } else {
    cout << "Document " << name << " was not found" << endl;
  }
}


