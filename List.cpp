#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <list.h>

using namespace std;

struct node{
  int info;
  node *next;
};

class List::ListImplementation
  node *head;
  public:
   ListImplementation();
   ListImplementation(const ListImplementation &list);
   ~ListImplementation();
   ListImplementation&operator=(const ListImplementation &list);
   void input(int n);
   void show();
   void push_beg(int n);
   void push_end(int n);
   void pop_end();
   void pop_beg();
   void push_list(int n,ListImplementation &list);
   node *get_head();
   void pop_list(int n);
};

List::List():pimpl(0){
  pimpl=new SetImplementation();
}

List::List(const List &spis){
  pimpl=new ListImplementation();
  node *temp,*temp1;
  if(!spis.pimpl->head){ pimpl->head=0; return;}
  pimpl->head=new node;
  (pimpl->head)->info=spis.head->info;
  (pimpl->head)->next=0;
  (pimpl->temp)=head;
  (pimpl->temp1)=(spis.pimpl->head)->next;
  while(pimpl->temp1){
    (pimpl->temp)->next=new node;
    (pimpl->temp)->next->info=pimpl->temp1->info;
    (pimpl->temp)->next->next=0;
    (pimpl->temp)=pimpl->temp->next;
    (pimpl->temp1)=pimpl->temp1->next;
  }
}

List::~List(){
  delete pimpl;
  pimpl=0;
}

List &List::operator=(const List &spis){
  return pimpl->operator=spis;
}



void List::input(int n){
  pimpl->input(n);
}

void List::show(){
  pimpl->show();
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

void List::push_list(int n,ListImplementation &list){
  pimpl->push_list(n,list)
}

node *List::get_head(){
  return pimpl->head;
}

void List::pop_list(int n){
  pimpl->pop_list(n);
}


List::ListImplementation::ListImplementation(){
  head=NULL;
}

List::ListImplementation::~ListImplementation(){
  while (head!=NULL){
  node *temp=head->next;
  delete head;
  head=temp;
}

void List::ListImplementation::input(int n){
  node *temp=new node;
  temp->info=n;
  temp->next=head;
  head=temp;
}

void List::ListImplementation::show(){
  node *temp=head;
  while (temp!=NULL){
    cout<<temp->info<<" ";
    temp=temp->next;
  }
}

void List::ListImplementation::push_beg(int n){
  node *temp1=new node;
  temp1->info=n;
  node *temp2=head;
  while(temp2->next)
    temp2=temp2->next;
  temp2->next=temp1;
  temp1->next=0;
  temp1=0;
}

void List::ListImplementation::push_end(int n){
  node *temp=new node;
  temp->info=n;
  temp->next=head;
  head=temp;
}

void List::ListImplementation::pop_end(){
  node *temp=head;
  head=head->next;
  delete temp;
  temp=0;
}

void List::ListImplementation::pop_beg(){
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

void List::ListImplementation::push_list(int n,ListImplementation &spis_t){
  node *temp=head;
  node *temp1;
  while(temp->info!=n){
    temp1=temp;
    temp=temp->next;
  }
  temp1->next=spis_t.get_head();
  while(temp1->next)
    temp1=temp1->next;
  temp1->next=temp;
}

void List::ListImplementation::pop_list(int n){
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

ListImplementation &List::ListImplementation::operator=(const ListImplementation &spis){
  node *temp,*temp1;
  if(this==&spis){return *this;}
  else{
    head=NULL;
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
    return *this;
  }
}

