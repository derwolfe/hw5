#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

#include "Document.h"
#include "llp.h"

/* 
 * default constructor that creates a list of no length
 * pointing the head, initializing the head and null pointers
 *
 * initializer list
 */
Double_list::Double_list (): size(0), head(NULL), tail(NULL) 
{}

Double_list::Double_list (const Double_list& a_list)
{
  if (a_list.head == NULL) {
    head = NULL;
    tail = NULL;
  /* 
   * checks to see if list is empty, if so, set the head to null
   * and you're finished, otherwise go through the deep copy set
   */
  } else {
    size = 0;
    assert (size == 0);
    Double_node *target = a_list.head;
      while (target != NULL) {
      item_add (target->item);
      target = target->next;
      size++; 
    }
  }
}

/* 
 * this will remove the first element of the loop on EACH 
 * iteration of the loop. Once, the list is empty it will 
 * stop. How to implement without index???
 */
Double_list::~Double_list() 
{
  while (!is_empty()) {
    pop();     
  }
}

/* 
 * Checks if the list's size = 0 and makes sure that head 
 * and tail are pointing to null. An assert statement
 * may not be the best way to check that head & tail are set to NULL
 */
bool Double_list::is_empty () const 
{
  if (size == 0) {
    return true;
  } else {
    return false;
  }
}

/* Accesses the private size variable */ 
int Double_list::get_length () const
{
  return size;
}


/* 
 * item_add - this should be used for UNORDERED lists, such as queues,
 * where adding to the tail, without indexing won't cause problems. 
 * The convention will be tail addition.
 */
void Double_list::item_add (Document *new_item)
{
  /* Two cases (1) the list is empty, and (2) the list isn't empty
   * CASE 1 - add initial node to the list, populate the item
   */
  Double_node *data_ptr  = new Double_node; 
  data_ptr->item         = new_item;
  if (size == 0) {
    head           = data_ptr;
    tail           = data_ptr;
    data_ptr->prev = NULL;
    data_ptr->next = NULL;
  /* 
   * CASE 2 - add on to the end. The head pointer doesn't
   * change because of the tail-addition.
   */
  } else if (size > 0) {
    data_ptr->prev  = tail;
    tail->next      = data_ptr;
    data_ptr->next  = NULL;
    tail            = data_ptr;
  }
  size++;
}
bool Double_list::remove (string name)
{
  /* WORKS!!!!!!
   * you should throw an exception
   * find  */
  Double_node *target = find (name);
  if (target == NULL) {
    return false; 
  
  /* CASE 1 - this is the first node, pointed at by head
   */
  } else if (size == 1) {
    target->prev = NULL;
    target->next = NULL;
    head = NULL;
    tail = NULL;
    delete target;
    size = 0;
    return true;
   /* CASE 2 - item is located at the tail, the edge case
   * of the size = 1, where head = node = tail, is 
   * already handled.
   */
  } else if (tail == target) {
    tail = target->prev;
    target->prev->next = NULL;
    delete target;
    target = NULL;
    size--;
    return true;
  /* CASE 3 - if target is first item in list with more than
   * one item.
   */
  } else if ((size > 1) && (head == target)) {
    head = target->next;
    target->next->prev = NULL;
    delete target;
    target = NULL;
    size--;
    return true;
  /* CASE 4 - the item is somewhere in the middle of the list
   * this only requires, finding it, moving several
   * pointers, deleting, decrementing size.
   */
  } else if ((size > 1) && 
      (head != target) && 
      (tail != target)) {
    target->prev->next = target->next;
    target->next->prev = target->prev;
    target = NULL;
    delete target;
    size--;
    return true;
  }
}

void Double_list::pop ()
{
  /* WORKS!
   * 3 cases - 
   * (1) empty list 
   * (2) one element in list
   * (3) more than one element in list
   */
  if (is_empty()) {
    size = 0;
  } else {
    Double_node *target = tail;
    if (size > 1) {
      tail    = tail->prev;
      delete target;
      target  = NULL;
      size--;
    } else if (size == 1) {
      delete target;
      tail    = NULL;
      head    = NULL;
      target  = NULL;
      size    = 0;
    }
  }
}

// TEST function using cout
void Double_list::print ()  
  /* WORKS for ints!!! */
{
  /* for node in list,*/ 
  Double_node *new_ptr = head;

  cout << "List items" << endl;
  cout << "---------- " << endl;
  while (new_ptr != NULL) {
    cout << *new_ptr->item << endl;
    /* if this is the tail, then stop
     * else set the new_ptr to next
     */
    if (tail == new_ptr) {
      break;
    } else {
      new_ptr = new_ptr->next;
    }
  }
  cout << "---------- " << endl;
}
/* 
 * PRIVATE find method that should search the list for the data item
 * once found, it should return a pointer to the node. Now other functions
 * can use find,
 */
Double_node* Double_list::find (string name) const
{
  /* WORKS!!!!!!
   */
  Double_node *target = head;
  int inc = 1;
  /* loop through the items. If the counter is ever greater than size, then 
   * the item isn't in the list, return a NULL pointer.
   *
   * You should throw an expception instead of a pointer.
   */
  while (inc <= (size + 1)) {
    if (inc == (size + 1)) {
      return NULL;
    } else if (target->item->get_name() == name) {
      return target;
    } else {
      target = target->next;
      inc++;
    }
  } 
}
/* WORKS!!!
 *
 * throw blocks seem useless if they completely halt the program
 * though, if the object isn't found, and you try to access any of its members
 * the program barfs and dies.
 */
Document* Double_list::retrieve(string name) const //throw(No_such_object_exception)
{
  Double_node *found = find (name);
  if (found == NULL) {
    return NULL;
//    throw No_such_object_exception
//      ("No_such_object_exception: the object you seek doesn't exist");
  } else {
    return found->item;
  }
}

