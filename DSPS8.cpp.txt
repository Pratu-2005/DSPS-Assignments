#include<iostream>
#include<cstring>
using namespace std;
int n,i;
class lsm{


string tt,aut,pub;
int prize,id;

lsm *next;

public:
void accept();
void displaycount();
void search();
void update();
void remove();








}*start=NULL,*temp=NULL;

void lsm:: accept(){

lsm *temp;
lsm *nnode;
nnode=new lsm;
cout<<"\nEnter book details id,title,author,publisher,price";
cin>>nnode->id>>nnode->tt>>nnode->aut>>nnode->pub>>nnode->prize;
nnode->next=NULL;
if(start==NULL){


start=nnode;




}
else{
temp=start;
while(temp->next!=NULL){


temp=temp->next;





}
temp->next=nnode;

}




}

void lsm::displaycount(){
int count=0;
lsm *temp;
temp=start;                  


while(temp!=NULL){

cout<<"\n"<<temp->id<<"\t"<<temp->tt<<"\t"<<temp->aut<<"\t"<<temp->pub<<"\t\t"<<temp->prize;
temp=temp->next;
count++;


}
cout<<"\ncount is"<<count;

}
void lsm::search(){
lsm *temp;
int f=0;
int id1;
cout<<"\nEnter ID which you want to search";
cin>>id1;
temp=start;
while(temp!=NULL){
if(temp->id==id1){
f=1;

cout<<"\n"<<temp->id<<"\t"<<temp->tt<<"\t"<<temp->aut<<"\t"<<temp->pub<<"\t"<<temp->prize;




break;
}

temp=temp->next;


}




if(f==0)


cout<<"\nNot Found";




}
void lsm::update() {
    lsm *temp;
    int f = 0;
    int id1;
    cout << "\nEnter ID of the book you want to update: ";
    cin >> id1;
    temp = start;

while (temp != NULL) {
if (temp->id == id1) {
  f = 1;
    cout << "\nEnter new book details (id, title, author, publisher, price): ";
     cin >> temp->id >> temp->tt >> temp->aut >> temp->pub >> temp->prize;
     cout << "\nBook details updated successfully!";
 break;
        }
        temp = temp->next;
    }

    if (f == 0)
        cout << "\nNot Found";
}
void lsm::remove() {
/*lsm *temp ,*p,*q;
int id1;
int f=0;
temp=start;
cout<<"\nEnter the id which you want delete";
while(temp!=NULL){


if(temp->id==id1){

f=1;
p=temp;
break;




}
q=temp;
temp=temp->next;






}
q->next=p->next;
delete p;
}
*/
    lsm *temp = start;
    lsm *prev = NULL;
 int id1;
 int found = 0;

    cout << "\nEnter the ID of the book you want to delete: ";
    cin >> id1;

    
while (temp != NULL) {
if (temp->id == id1) {
  found = 1;

            
if (temp == start) {
  start = temp->next;
            } 
else {
                
   prev->next = temp->next;
            }
delete temp;
  cout << "\nBook with ID " << id1 << " deleted successfully!";
   break;
        }
        
  prev = temp;
   temp = temp->next;
    }

if (!found)
 cout << "\nBook with ID " << id1 << " not found.";
}




int main(){
lsm s;
int ch;

do{

cout<<"\n menu";
cout<<"\n1.accept\n2.display\n3.search\n4.update\n5.remove";
cout<<"\nEnter the choice:";
cin>>ch;
switch(ch){


case 1:

s.accept();
break;
case 2:
cout<<"\n"<<"ID"<<"\t"<<"title"<<"\t"<<"author"<<"\t"<<"Publisher"<<"\t"<<"prize";

s.displaycount();
break;
case 3:
s.search();
break;
case 4:
s.update();
break;
case 5:
s.remove();
break;
}
}while(ch!=0);

return 0;






}