#include "Linked_List.h"

using namespace std;

Linked_List::Linked_List()
{

}

Linked_List::~Linked_List()
{

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

}

int Linked_List::get_size()
{

}

void Linked_List::insert(int index, Document* document)
{

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
