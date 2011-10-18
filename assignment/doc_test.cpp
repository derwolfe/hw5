#include <stdio.h>
#include <iostream>

using namespace std;

#include "Document.h"
#include "llp.h"
#include "Stack.h"
#include "Queue.h"

int main ()
{
  Double_list *docs = new Double_list;
  Document *billy = new Document ("a" , "8");
  // you need to throw an error if the priority is outside of the range
  Document *c = new Document("c", "2");
  Document *b = new Document("b", "1");
  docs->doc_add(b);
  docs->doc_add (billy);
  docs->doc_add(c);
//  docs->print();
//  cout << "\nTest Find" << endl;
//  Document* test = docs->retrieve("a");
//  Document* tr = docs->retrieve("zed");
//  
//  cout << "\nretr test\n"<< *test << endl;
//  docs->print(); 
//  cout << "\ndeq test\n" << *docs->dequeue() << endl; 

  Stack *s = new Stack;
  s->push(b);
  s->push(c);
  cout << *s->pop() << endl;
 // s->pop();
  cout << "stack test" << endl;
  cout << *s << endl;
  //
/* Queue test 
 */
  cout << "q test" << endl;
  Queue *fq = new Queue;
  fq->enqueue(b);
//  cout << *fq << endl;
//  cout << *s << endl;
  fq->enqueue(billy);
  fq->dequeue();
  cout << *fq << endl;
  //  s->push(fq->dequeue());
//  cout << *s << endl;
//  fq->dequeue();
  //throw error upon too many dequeues!
  //fq->dequeue();
//  fq->is_empty(); 
//  fq->enqueue(billy);
//  fq->enqueue(c);
//  fq->withdraw("a");
//  fq->enqueue(b);
//  cout << *fq << endl;
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
