#include "Office.h"

using namespace std;

/*
 * Constructor and destructor. Note that each element created with a
 * "new" statement in the constructor has a corresponding "delete"
 * statement in the destructor.
 */
Office::Office()
{

}

Office::~Office()
{

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

}

void Office::submit_document(string name, string priority)
{

}

void Office::read_document()
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
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
   */
      cout << "Error: bad priority on document:" << cur << endl;
}

void Office::withdraw_document(string name)
{

  /*
   * These are the narrative ouput messages you will need for this
   * routine, but you have to figure out the controlling code.
   */
  
    cout << "Document " << name << " removed from inbox" << endl;

    cout << "Document " << name << " removed from queue 1" << endl;

    cout << "Document " << name << " removed from queue 2" << endl;

    cout << "Document " << name << " removed from queue 3" << endl;

    cout << "Document " << name << " was not found" << endl;


}


