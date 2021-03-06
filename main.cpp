#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "List.h"

using namespace std;

class ConsoleList: public List{
  public:
    void output(ostream &out) const;
};

ostream &operator<<(ostream &out, const ConsoleList &list){
  list.output(out);
  return out;
}

void ConsoleList::output(ostream &out) const{
  int info1;
  if(nextInfo(true,info1))
    out<<info1<<" ";
  while(nextInfo(false,info1))
    out<<info1<<" ";
}

int main(){
  int m,n,k,z;
  ConsoleList spis,spis_t;
  while(1){
    cout<<endl<<"Select an action: "<<endl;
    cout<<"__________________"<<endl;
    cout<<"1.Sozdat' spisok: "<<endl;
    cout<<"2.Dobavit' element v nachalo: "<<endl;
    cout<<"3.Daobavit' element v konec: "<<endl;
    cout<<"4.Udalit' element iz nachala: "<<endl;
    cout<<"5.Udalit' element iz konca: "<<endl;
    cout<<"6.Vstavit' podspisok: "<<endl;
    cout<<"7.Udalit' podspisok: "<<endl;
    cout<<"8.Exit:"<<endl;
    cin>>z;
    switch(z){
       case 1:{
         cout<<endl<<"Vvedite kolichestvo elementov spiska: "; cin>>m;
         for (int i=0;i<m;i++){
           cout<<"Vvedite "<<i+1<<" element spiska: "; cin>>n;
           spis.input(n);
         }
         cout<<spis<<endl;
         break;
       }
       case 2:{
         cout<<endl<<"Vvedite element dlya dobavlenia v nachalo: ";cin>>n;
         spis.push_beg(n);
         cout<<spis<<endl;
         break;
       }
       case 3:{
         cout<<endl<<"Vvedite element dlya dobavlenia v konec: ";cin>>n;
         spis.push_end(n);
         cout<<spis<<endl;
         break;
       }
       case 4:{
         cout<<endl<<"Udalyaem element:"<<endl;
         spis.pop_beg();
         cout<<spis<<endl;
         break;
       }
       case 5:{
         cout<<endl<<"Udalyaem element:"<<endl;
         spis.pop_end();
         cout<<spis<<endl;
         break;
       }
       case 6:{
         cout<<endl<<"Vvedite kolichestvo elementov,kotoroe hotite dobavit': ";cin>>m;
         cout<<endl<<"Vvedite cifru,posle kotoroi vstavit' podstroku: "; cin>>n;
         for(int i=0;i<m;i++){
           cout<<"Vvedite "<<i+1<<" element spiska: "; cin>>k;
           spis_t.input(k);
         }
         cout<<spis_t<<endl;
         spis.push_list(n,spis_t);
         cout<<endl;
         cout<<spis<<endl;
         break;
       }
       case 7:{
         cout<<endl<<"Vvedite kolichestvo elementov,kotoroe hotite udalit': ";cin>>m;
         cout<<endl<<"Vvedite cifru,posle kotoroi udalit podstroku: "; cin>>n;
         for(int i=0;i<m;i++)
            spis.pop_list(n);
         cout<<spis<<endl;
         break;
       }
       case 8:{
         cout<<"Good-Bye!"<<endl;
         getch();
         exit(1);
       }
    }
  }
  getch();
  return 0;
}
