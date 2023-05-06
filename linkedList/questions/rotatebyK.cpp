#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};


void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}


void insertAtTail(node* &head,int val){
     node* n=new node(val);
     
     if(head==NULL){
         head=n;
         return;
     }
     node* temp=head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=n;
}

void print(node* head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int length(node* head){
    int count=0; 
    node* temp= head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

node* rotate(node* head,int k){
    int l=1;
    node* curr=head;
    while(curr->next!=NULL){
           curr=curr->next;
           l++;
    }
    if(l!=k){
      curr->next=head;
      k=k%l;
      k=l-k;
      while(k--){
           curr=curr->next;
      }
      head=curr->next;
      curr->next=NULL;
    
    }
   return head;
}

int main(){
    node* head=NULL;
    int a[7]={1,2,3,4,5,6,7};
    for(int i=0; i<7; i++){
        insertAtTail(head,a[i]);
    }
    print(head);
    node* newhead=rotate(head,2);
    print(newhead);
    return 0;
}