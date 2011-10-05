#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Office.h"

using namespace std;

enum Command
  {
    ENTER,
    LEAVE,
    PRINT,
    READ,
    SORT_INBOX,
    SUBMIT,
    WITHDRAW,

    INVALID

  };

Command identify_next_command(const string& cmd_str)
{
  Command command;

  if (cmd_str.compare("enter") == 0) {
    command = ENTER;
  } else if (cmd_str.compare("leave") == 0) {
    command = LEAVE;
  } else if (cmd_str.compare("print") == 0) {
    command = PRINT;
  } else if (cmd_str.compare("read") == 0) {
    command = READ;
  } else if (cmd_str.compare("sort-inbox") == 0) {
    command = SORT_INBOX;
  } else if (cmd_str.compare("submit") == 0) {
    command = SUBMIT;
  } else if (cmd_str.compare("withdraw") == 0) {
    command = WITHDRAW;
  } else {
    command = INVALID;
  }

  return command;
}

int main(int argc, char* argv[])
{
  string   cmd_str;
  Command  command;
  string   doc_name;
  string   doc_priority;
  ifstream fin;
  Office  *office = new Office();

  if (argc < 2) {
    cerr << "Usage error: ./office_sim input.txt" << endl;
    exit(1);
  }

  /*
   * Open the input file
   */
  fin.open(argv[1]);
  if ( !fin.good() ) {
    /*
     * Something is wrong. Complain and die.
     */
    cout << "Error: could not open input file:" << argv[1] << endl;
    exit(1);
  }

  /*
   * Create an instance of the office class, which is aholder for
   * everything else.
   */
  office = new Office();

  /*
   * While there is another command to read from the input file, read
   * it into cmd_str, identify the command, act accordingly.
   */
  while (fin >> cmd_str) {
    command = identify_next_command(cmd_str);

    switch (command) {
    case ENTER:
      /*
       * Worker Bee arrives at the office
       */
      office->enter();
      cout << "ENTERED"   << endl;
      break;

    case INVALID:
      /*
       * identify_next_command does not know the command read
       * in. Possibly, reading an earlier command either did not read
       * enough arguments, or read too few, and left the program out
       * of sync with the input.
       */
      cout << "Error: invalid command string: " << cmd_str << endl;
      break;

    case LEAVE:
      /*
       * Worker Bee leaves the office. Read count is supposed to
       * reflect how many documents the worker read since arriving at
       * the office.
       *
       * FIXME: I think Leaving should imply that the worker has
       * finished the current document
       */
      office->leave();
      cout << "LEFT"      << endl;
      cout << *office;
      cout << "READCNT: " << office->get_read_count() << endl << endl;
      break;

    case PRINT:
      /*
       * Print the state of the office
       */
      cout << *office << endl;
      break;

    case READ:
      /*
       * Worker Bee reads a document - should be front of highest
       * priority non-empty document queue. The read_document routine
       * prints out a narrative statement because it is hard to know
       * what document is read at this location inthe code.
       * 
       */
      office->read_document();
      break;

    case SORT_INBOX:
      /*
       * Worker Bee decides to sort the in-box rather than read the
       * next document
       *
       * FIXME: I think sorting the in_box should imply the worker has
       * finished the current document.
       */
      office->sort_inbox();
      cout << "In Box Sorted"   << endl;
      break;

    case SUBMIT:
      /*
       * Document submitted to the office
       *
       * Two arguments: Name and Priority
       */
      fin >> doc_name >> doc_priority;
      office->submit_document(doc_name, doc_priority);
      cout << "Submit: " << doc_name << " Priority: " << doc_priority  << endl;
      break;

    case WITHDRAW:
      /*
       * Somebody made a mistake and came to get back a document that
       * is already in the office, although we probably have to handle
       * confused people who try to wthdraw a document that is not
       * actually in the office.
       */
      fin >> doc_name;
      office->withdraw_document(doc_name);
      break;

    default:
      /*
       * Double confusion: identify_next_command managed to return an
       * invlaide code. Hould be impossible, but suspenders and belt
       * is better than only one.
       */
      cout << "Error: invalid return value from identify_next_command: " << command << endl;
      cout << "Error: command string causing this: " << cmd_str << endl;
      break;
    }
  }

  /*
   * All processing of office simulation commands is
   * finished. Deallocate the office instance and close the input port
   * for neatness' sake.
   */
  delete office;
  fin.close();

  /*
   * Zero is the conventional exit code for success on POSIX
   * systems. Non-zero return values are generally error
   * codes. Sometimes negative values are errors and positive are
   * result codes for forms of success.
   */
  exit(0);
}
