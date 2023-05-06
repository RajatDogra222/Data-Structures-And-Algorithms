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
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
// int middle(node* head){
//     int l=length(head);
//     int mid=0;
//     if(l%2==0){
//        mid=l/2;
//     }
//     else{
//         mid=l/2+1;
//     }
//     node* temp=head;
//     int count=1;
//     while(count!=mid){
//         temp=temp->next;
//         count++;
//     }
//     return temp->data;
// }

int middle(node* head){
    node* fast=head;
    node* slow=head;
    while(fast->next->next!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
int main(){
    node* head=NULL;
    int a[8]={1,2,3,4,5,6,7,8};
    for(int i=0; i<8; i++){
        insertAtTail(head,a[i]);
    }
    cout<<middle(head);
    
    return 0;
}