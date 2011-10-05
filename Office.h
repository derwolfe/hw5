#ifndef OFFICE_H
#define OFFICE_H

#include <iostream>
#include <string>

#include "Document.h"
#include "Stack.h"
#include "Queue.h"

class Office
{
 private:
  /*
   * Data structures representing the state of the in_box and the
   * document rpiority queues.
   */
  Stack *inbox_stack;
  Queue *priority_queue_one;
  Queue *priority_queue_two;
  Queue *priority_queue_three;

  /*
   * This refers to the document the Worker Bee is currently reading,
   * or is NULL if no document is currently being read.
   */
  Document *current_document;
  bool      in_office;          /* Worker Bee in office: T/F */

  /*
   * This counts the number of documents read during each period
   * during which the worker is in the office. It is reset to zero on
   * each entry.
   */
  int       read_count;     

 public:
  Office();
  ~Office();

  void enter();
  int  get_read_count();
  void leave();
  void read_document();
  void sort_inbox();
  void submit_document(std::string name, std::string priority);
  void withdraw_document(std::string name);

  friend std::ostream& operator<<(std::ostream &os, Office &office); 

};

#endif
