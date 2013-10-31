#ifndef LIST_H
#define LIST_H



class List{
  class ListImpl;
  ListImpl *pimpl;
  public:
    List();
    List(const List &);
    ~List();
    void input(int n);
    void push_beg(int n);
    void push_end(int n);
    void pop_end();
    void pop_beg();
    void push_list(int,List &);
    void pop_list(int);
  protected:
    bool nextInfo(bool start,int &info) const;
};


#endif // LIST_H
