#include "Linked_List.h"

using namespace std;

Linked_List::Linked_List()
{
  size = 0;
  head = NULL;
  tail = NULL; // add the tail
}

Linked_List::~Linked_List()
{
   while ( !is_empty ()) {
    pop ();     
  }
}

void Linked_List::print(ostream& os)
{
  Node* cur = head;

  while (cur != NULL) {
    os << cur->doc->get_name() << " ";
    cur = cur->next;
  }
}

bool Linked_List::is_empty()
{  
  if ( size == 0 ) {
    //assert ( head == NULL );
    return true;
  } else {
    return false;
  }
}

int Linked_List::get_size()
{
  return size;
}

void Linked_List::insert(int index, Document* document)
{
  /* why using an index??
   *
   * Two cases (1) the list is empty, and (2) the list isn't empty
   * CASE 1 - add initial node to the list, populate the item
   */
  Double_node *data_ptr  = new Double_node; 
  data_ptr->item         = document;
  if ( size == 0 ) {
    head           = data_ptr;
    tail           = data_ptr;
    data_ptr->prev = NULL;
    data_ptr->next = NULL;
  /* 
   * CASE 2 - add on to the end. The head pointer doesn't
   * change because of the tail-addition.
   */
  } else if ( size > 0 ) {
    data_ptr->prev  = tail;
    tail->next      = data_ptr;
    data_ptr->next  = NULL;
    tail            = data_ptr;
  }
  size++;

}

Linked_List::Node* Linked_List::find(int index)
{

}

void Linked_List::remove(int index)
{

}

bool Linked_List::remove(string name)
{

}


Document* Linked_List::retrieve(int index)
{

}
