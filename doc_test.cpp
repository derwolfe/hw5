#include <stdio.h>
#include <iostream>

using namespace std;

#include "Document.h"
#include "llp.h"

int main ()
{
  Double_list *docs = new Double_list;
  Document *billy = new Document ("a" , "8");
  // you need to throw an error if the priority is outside of the range

  Document *c = new Document("c", "2");
  Document *lp = new Document("b", "1");
  docs->doc_add(lp);
  docs->doc_add (billy);
  docs->doc_add(c);
//  docs->print();
//  cout << "\nTest Find" << endl;
//  Document* test = docs->retrieve("a");
//  Document* tr = docs->retrieve("zed");
//  cout << *test << endl;
  docs->print(); 
//  cout << "\ndeq test\n" << *docs->dequeue() << endl; 
//  docs->print();
//  //seg fault on find 
//  //cout << tr << endl;
//  cout << "\nPop Test\n" << *docs->pop() << endl;
//  cout << "\nPop Test\n" << *docs->pop() << endl;
//  Document *by = new Document ("d", "1");
//  Document *hurl = new Document ("e", "3");
//  docs->doc_add (by); 
//  docs->doc_add (hurl); 
//  docs->print();
  return 0;
}
