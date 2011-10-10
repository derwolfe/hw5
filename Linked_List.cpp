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
    remove (0);     
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
  if (size == 0) {
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
  /* you should have a throw mechanism if the index is out of
   * range, otherwise, all should work. 
   *
   * use a zero based index, i.e. head = 0.
   */
  Node *node = new Node; 
  node->doc   = document;
  if (size == 0) {
    head = node;
    tail = node;
    node->doc = doc;
    node->next = NULL;
    /* you could also try comparing size and index
     * if ind >= size, tail; if ind < size, ind middle,
     * if ind == 0, ins to head, but make sure about the overlap
     * of ins to 0, w/ size == 0, and ins 0 w/ size > 0;
     *
     * tail should not need to be reset if adding to head
     */
  } else if ((size > 0) && (index == 0)) {
    node->next = head;
    head = node;
  } else if ((size > 0) && (index < size )) {
    /* find node at index - 1, set pointers
     * insert to head has been handled, so this 
     * case will not handle it
     * this also ignores insert to tail, by checking if
     * index < size. 
     */
    Node *target_prev = find (index - 1);
    node->next = target->next;
    target->next = node;
    /* the tail pointer gives quick access to the node
     */
  } else if ((size > 0) && ( index >= size )) {
    tail->next = node;
    node->next = NULL;
    tail = node;
  }
  size++;
}
/* find will be a utility function employed by remove
 */
Linked_List::Node* Linked_List::find(int index)
{

}
void Linked_List::remove(int index)
{ 

}
/* find the item using FIND, then delete it
 */
bool Linked_List::remove(string name)
{

}

/* public method that returns the actual data item
 * contained in the node. Use find, take one step further
 * and give the item contained in the node.
 */
Document* Linked_List::retrieve(int index)
{

}
