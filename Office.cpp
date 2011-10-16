#include "Office.h"

using namespace std;

/*
 * Constructor and destructor. Note that each element created with a
 * "new" statement in the constructor has a corresponding "delete"
 * statement in the destructor.
 */
Office::Office()
{
  inbox_stack = new Stack;
  priority_queue_one = new Queue;
  priority_queue_two = new Queue;
  priority_queue_three = new Queue;
  
  in_office = false;
  read_count = 0;
  Document* current_document = NULL;
}

/* what all needs to be deconstructed and deallocated? 
 * anything with new, delete.
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
   *
   * 2 scenarios, either in or out of office.
   */
  if (in_office == true) {  
    cout << "Error: someone is already in the office" << endl;
    cout << "You cannot enter until he leaves" << endl;
  } else if (in_office == false) {
    in_office = true;
    cout << "You have entered the office" << endl;
  }
}

void Office::leave()
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   */
  if (in_office == true) {
    in_office = false;
  } else {
    cout << "Error: there is nobody in the office to leave" << endl;
  }
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
  Document *doc = new Document(name, priority);
  inbox_stack->push(doc);
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
   * also, if no worker is in the office, no one can read.
   *
   */
  if (in_office) {
    if (priority_queue_one->is_empty() &&
        priority_queue_two->is_empty() &&
        priority_queue_three->is_empty()) {
      cout << "No more documents to read" << endl;
    } else {
      if (!priority_queue_one->is_empty()) {
        current_document = priority_queue_one->dequeue();
        read_count++;
      } else if (!priority_queue_two->is_empty()) {
        current_document = priority_queue_two->dequeue();
        read_count++;
      } else if (!priority_queue_three->is_empty()) {
        current_document = priority_queue_three->dequeue();
        read_count++;
      }
      cout << "READER : START " << current_document->get_name() 
           << endl << endl;
    }
  } else { 
    cout << "Error: cannot read when nobody is in the office" << endl;
  }
}

void Office::sort_inbox()
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   *
   * for each of the documents in the stack, beginning with the top, 
   * pop it off of the stack, and enqueue it based on priority
   *
   * pop should be decrementing size of inbox_stack, but I don't know if it
   * is.
   */
  Document* target;
  /* Pop isn't actually popping!
   */
 // while (!inbox_stack->is_empty()) {
  for (int i = 0; i < 6; i++) { 
    target = inbox_stack->pop();
    cout << *target << endl;
    if (target->get_priority() == PRIORITY_1) {
      priority_queue_one->enqueue(target);
    
    } else if (target->get_priority() == PRIORITY_2) {
      priority_queue_two->enqueue(target);
    
    } else if (target->get_priority() == PRIORITY_3) {
      priority_queue_three->enqueue(target);
 //   } else {
 //     cout << "Error: bad priority on document:" << target << endl;
    }
  } cout << *inbox_stack << endl;
    cout << *priority_queue_one << endl;
    cout << *priority_queue_two << endl;
    cout << *priority_queue_three << endl;
}
  

void Office::withdraw_document(string name)
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   *
   * Each of these statements is meant to try to find the document in the
   * stack, if it does, it should remove it from the stack, 
   * otherwise, check the next structure.
   */
  Document* stack_target = inbox_stack->peek(name);
  Document* p1_target = priority_queue_one->peek(name);
  Document* p2_target = priority_queue_two->peek(name);
  Document* p3_target = priority_queue_three->peek(name);

  if (stack_target != NULL) {
    inbox_stack->withdraw(name);
    cout << "Document " << name << " removed from inbox" << endl;
  } else if (p1_target != NULL) {
    priority_queue_one->withdraw(name);
    cout << "Document " << name << " removed from queue 1" << endl;
  } else if (p2_target != NULL) {
    priority_queue_two->withdraw(name);
    cout << "Document " << name << " removed from queue 2" << endl;
  } else if (p3_target != NULL) {
    priority_queue_three->withdraw(name);
    cout << "Document " << name << " removed from queue 3" << endl;
  } else {
    cout << "Document " << name << " was not found" << endl;
  }
  stack_target = NULL;
  p1_target = NULL;
  p2_target = NULL;
  p3_target = NULL;
} 



