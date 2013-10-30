#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
class List{
  class ListImplementation;
  ListImplementation *pimpl;
  public:
    List() {head=NULL;}
    List(const List &);
    ~List();
    List&operator=(const List &);
    void input(int n);
    void show();
    void pop(int n);
    void push_beg(int n);
    void push_end(int n);
    void pop_end();
    void pop_beg();
    void push_list(int,List &);
    node *get_head(){return head;};
    void pop_list(int);
};


#endif // LIST_H_INCLUDED
