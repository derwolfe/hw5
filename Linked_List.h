#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

#include "Document.h"

class Linked_List
{
 private:
  struct Node
  {
    Document *doc;
    Node     *next;
    Node     *prev;
  };

  Node *head;
  Node *tail;
  int   size;
/* the index is basically how deeply you want it to search
 * find by depth.
 */
  Node *find(int index);

 public:
  Linked_List();
  ~Linked_List();

  int        get_size();
  void       insert(int index, Document* document);
  bool       is_empty();
  void       print(std::ostream& os);
  void       remove(int index);
  bool       remove(std::string name);
  Document  *retrieve(int index);
};

#endif
