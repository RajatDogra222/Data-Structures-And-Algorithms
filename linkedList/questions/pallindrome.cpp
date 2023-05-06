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

node* middle(node* head){
    node* slow=head;
    node* fast=head;

    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<slow->data<<endl;
    return slow;
}

node* reverse(node* &head){
    //  if(head==NULL || head->next==NULL){
    //      return head;
    //  }
    //  node* newhead=reverse(head->next);
    //  head->next->next=head;
    //  head->next=NULL;
    //  return newhead;

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }

    return prevptr;
}

bool pallindrome(node* head){
    node* mid=middle(head);
    mid->next=reverse(mid->next);

    node* temp1=head;
    node* temp2=mid->next;

    while(temp2!=NULL){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}

int main(){
    node* head=NULL;
    int a[7]={1,2,3,4,5,2,1};
    for(int i=0; i<7; i++){
        insertAtTail(head,a[i]);
    }
    print(head);

    cout<<pallindrome(head)<<endl;
    print(head);

    return 0;
}