#include "Document.h"

using namespace std;
/* default constructor that will set no elements, this
 * was needed in the previous assignement"
 */ 
Document::Document()
{
  name = "";
  priority = PRIORITY_3;
}

Document::Document(string in_name, string in_priority)
{
  name = in_name;
  priority = convert_priority(in_priority);
}

ostream& operator<<(ostream &os, Document &document)
{
  os << "document"   << endl;
  os << "name: "     << document.name << endl;
  os << "priority: " << document.priority + 1 << endl;
    
  return os;
}
/* priorities are enumerated -- switch statements?
 */
Priority Document::convert_priority(string str_priority)
{
  if (str_priority.compare("1") == 0) {
    return PRIORITY_1;
  } else if (str_priority.compare("2") == 0) {
    return PRIORITY_2;
  } else if (str_priority.compare("3") == 0) {
    return PRIORITY_3;
  } else {
    return PRIORITY_3;
  } 
}

Priority Document::get_priority()
{
  return priority;
}

string Document::get_name()
{
  return name;
}


