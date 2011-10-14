/*llp.h
 *#include "no_such_object_exception.h"
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

#include "Document.h"

struct Double_node 
{
  Document      *doc; 
  /* 
   * pointers to the previous and next nodes, 
   * this is the distinguishing feature of the doubly
   * linked list
   */
  Double_node   *prev;
  Double_node   *next;
};

class Double_list 
{
  public:
    /* constructor for empty object */
    Double_list ();
    /* 
     * copy constructor needed to be able to make deep copies
     * of objects. Should the assignment operator have been overloaded
     * I cannot figure out how to call this constructor explicitly.
     */
    Double_list (const Double_list& a_list);
    
    /* destructor - basically a tail ended pop */
    ~Double_list ();

    /* checks if the node is empty */
    bool is_empty () const;

    /* returns the length */
    int get_length () const;

    /* adds the doc to the end of the list.*/
    void doc_add (Document *new_doc);

    /* finds then remove the  node */
    bool remove (string name);

    /* remove without providing pointer*/
    void kill ();
   
    /* pop function - tail end pop */
    Document* pop ();

    Document* dequeue ();
    
    void print (std::ostream &os);

    Document* retrieve (string name) const;
//      throw (No_such_object_exception);

  private:

    /* 
     * the total size of the list
     * and and a pointer to the node
     */
    int            size;
    Double_node   *head;
    Double_node   *tail;
    Double_node   *find (string name) const;
};

#endif
