#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    
    node(int val){
        data=val;
        prev=next=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
       head->prev=n;
    }
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
    n->prev=temp;
}


void deleteAtHead(node* &head){
    if(head==NULL){
        return;
    }
    
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}


void deletion(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}

void print(node* head){
    node* temp=head;
    cout<<"NULL--";
    while(temp!=NULL){
        cout<<temp->data<<"--";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}



int main(){
     node* head=NULL;
     int a[6]={1,2,3,4,5,6};
     for(int i=0; i<6; i++){
         insertAtTail(head,a[i]);
     }
     print(head);
    //  deletion(head,1);
    //  print(head);
    //  deleteAtHead(head);
    //  print(head);

    return 0;
}