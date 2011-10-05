#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

enum Priority {
  PRIORITY_1,
  PRIORITY_2,
  PRIORITY_3
};

class Document
{
 private:
  std::string name;
  Priority    priority;

 public:
  Document(std::string in_name, std::string in_priority);
        
  std::string get_name();
  Priority    get_priority();

  friend std::ostream& operator<<(std::ostream &os, Document &document);

 private:
  Priority convert_priority(std::string str_priority);
};

#endif
