#include <iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
string customer_name;
Node *link;
};

Node *front = NULL;
Node *rear = NULL;

bool isempty()
{
 if(front == NULL && rear == NULL){
 return true;}
 else{
 return false;
}
}

void enqueue ( string name )
{
 Node *ptr = new Node();
 ptr->customer_name= name;
 ptr->link = NULL;


 if( front == NULL )
 {
  front = ptr;
  rear = ptr;
 }
 else
 {
  rear ->link = ptr;
  rear = ptr;
 }
}

void dequeue ( )
{
 if( isempty() )
 cout<<"Queue is empty\n";
 else
 if( front == rear)
 {
  free(front);
  front = NULL;
  rear = NULL;
 }
 else
 {
  Node *ptr = front;
  front = front->link;
  free(ptr);
 }
}

void showfront( )
{
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"Customer at front is:"<<front->customer_name<<"\n";
}

void displayQueue()
{  
 if (isempty())
  cout<<"Queue is empty\n";
 else
 {
  Node *ptr = front;
  while( ptr !=NULL)
  {
   cout<<"\t"<<ptr->customer_name<<"\t  "<<endl;
   ptr= ptr->link;
  
  }
 }
}

