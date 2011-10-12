//llp.h
#include "no_such_object_exception.h"

struct Double_node 
{
  Document      *item; 
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
    Double_list ( const Double_list& a_list );
    
    /* destructor - basically a tail ended pop */
    ~Double_list ();

    /* checks if the node is empty */
    bool is_empty () const;

    /* returns the length */
    int get_length () const;

    /* adds the item to the end of the list.*/
    void item_add ( Document *new_item );

    /* finds then remove the  node */
    bool remove ( string name );
   
    /* pop function - tail end pop */
    void pop ();
    /* returns a sought item searched by item name, i don't
     * think this will work
     */
//    friend std::ostream& operator<<(std::ostream &os, Double_node &in_node);
    
    void print ();

    Document* retrieve ( string name ) const;
//      throw (No_such_object_exception);

  private:

    /* 
     * the total size of the list
     * and and a pointer to the node
     */
    int            size;
    Double_node   *head;
    Double_node   *tail;
    Double_node   *find ( string name ) const;
};



