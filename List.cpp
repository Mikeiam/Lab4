#include "list.h"


struct node{
  int info;
  node *next;
};

class List::ListImpl{
  node *head;
  public:
   ListImpl();
   ListImpl(const ListImpl &list);
   ~ListImpl();
   void input(int n);
   void push_beg(int n);
   void push_end(int n);
   void pop_end();
   void pop_beg();
   void push_list(int n,ListImpl &list);
   void pop_list(int n);
   bool nextInfo(bool start,int &info) const;
};

List::List():pimpl(0){
  pimpl=new ListImpl();
}

List::List(const List &spis){
  pimpl=new ListImpl(*spis.pimpl);
}

List::~List(){
  delete pimpl;
  pimpl=0;
}

bool List::nextInfo(bool start,int &info) const{
  return pimpl->nextInfo(start,info);
}

void List::input(int n){
  pimpl->input(n);
}

void List::push_beg(int n){
  pimpl->push_beg(n);
}

void List::push_end(int n){
  pimpl->push_end(n);
}

void List::pop_end(){
  pimpl->pop_end();
}

void List::pop_beg(){
  pimpl->pop_beg();
}

void List::push_list(int n,List &list){
  pimpl->push_list(n,*list.pimpl);
}

void List::pop_list(int n){
  pimpl->pop_list(n);
}




List::ListImpl::ListImpl(){
  head=0;
}


List::ListImpl::ListImpl(const ListImpl &spis){
  node *temp,*temp1;
  if(!spis.head){ head=0; return;}
  head=new node;
  head->info=spis.head->info;
  head->next=0;
  temp=head;
  temp1=spis.head->next;
  while(temp1){
    temp->next=new node;
    temp->next->info=temp1->info;
    temp->next->next=0;
    temp=temp->next;
    temp1=temp1->next;
  }
}


List::ListImpl::~ListImpl(){
  while(head){
    node *temp=head->next;
    delete head;
    head=temp;
  }
}


void List::ListImpl::input(int n){
  node *temp=new node;
  temp->info=n;
  temp->next=head;
  head=temp;
}


void List::ListImpl::push_beg(int n){
  node *temp1=new node;
  temp1->info=n;
  node *temp2=head;
  while(temp2->next)
    temp2=temp2->next;
  temp2->next=temp1;
  temp1->next=0;
  temp1=0;
}


void List::ListImpl::push_end(int n){
  node *temp=new node;
  temp->info=n;
  temp->next=head;
  head=temp;
}


void List::ListImpl::pop_end(){
  node *temp=head;
  head=head->next;
  delete temp;
  temp=0;
}


void List::ListImpl::pop_beg(){
  node *temp2;
  node *temp=head;
  while(temp->next->next)
    temp=temp->next;
  temp2=temp->next;
  temp->next=0;
  temp2->next=0;
  delete temp2;
  temp2=0;
}


void List::ListImpl::push_list(int n,ListImpl &spis_t){
  node *temp=head;
  node *temp1;
  while(temp->info!=n){
    temp1=temp;
    temp=temp->next;
  }
  temp1->next=spis_t.head;
  while(temp1->next)
    temp1=temp1->next;
  temp1->next=temp;
}


void List::ListImpl::pop_list(int n){
  node *temp2;
  node *temp=head;
  while(temp->next->info!=n){
    temp2=temp;
    temp=temp->next;
  }
  temp2->next=temp->next;
  temp->next=0;
  delete temp;
  temp=0;
}


bool List::ListImpl::nextInfo(bool start,int &info) const{
  static node *now;
  if(start)
    now=head;
  bool value=now!=0;
  if(value){
    info=now->info;
    now=now->next;
  }
  return value;
}
