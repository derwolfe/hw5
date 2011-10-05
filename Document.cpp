#include "Document.h"

using namespace std;

Document::Document(string in_name, string in_priority)
{

}

ostream& operator<<(ostream &os, Document &document)
{
  os << "document"   << endl;
  os << "name: "     << document.name << endl;
  os << "priority: " << document.priority + 1 << endl;
    
  return os;
}

Priority Document::convert_priority(string str_priority)
{

}

Priority Document::get_priority()
{

}

string Document::get_name()
{

}


