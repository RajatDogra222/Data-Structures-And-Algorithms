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

// node* mergetwo(node* head1,node* head2){
//      node* newhead=NULL;
//      node* temp;

//      while(head1!=NULL && head2!=NULL){

//          if(head1->data < head2->data){
//              if(newhead==NULL){
//                  node* n=new node(head1->data);
//                  newhead=n;
//                  temp=newhead;
//              }
//              else{
//                  node* n=new node(head1->data);
//                  temp->next=n;
//                  temp=temp->next;
//              }
//              head1=head1->next;

//          }
//          else if(head2->data < head1->data){
//              if(newhead==NULL){
//                  node* n=new node(head2->data);
//                  newhead=n;
//                  temp=newhead;
//              }
//              else{
//                  node* n=new node(head2->data);
//                   temp->next=n;
//                   temp=temp->next;
//              }
//              head2=head2->next;
//          }
//          else{
//              if(newhead==NULL){
//                  node* n=new node(head2->data);
//                  newhead=n;
//                  temp=newhead;
//              }
//              else{
//                  node* n=new node(head2->data);
//                   temp->next=n;
//                   temp=temp->next;
//              }
             
//               head2=head2->next;
//          }
//      }

//      while(head1!=NULL){
//         node* n=new node(head1->data);
//         temp->next=n;
//         temp=temp->next;
//         head1=head1->next;
//      }
//      while(head2!=NULL){
//         node* n=new node(head2->data);
//         temp->next=n;
//         temp=temp->next;
//         head2=head2->next;
//      }

//      return newhead;
// }


node* mergetwo(node* head1,node* head2){
    node* l1=NULL;
    node* l2=NULL;

    if(head1->data<= head2->data){
        l1=head1;
        l2=head2;
    }
    else{
        l1=head2;
        l2=head1;
    }
    node* res=l1;
    node * temp=NULL;
    while(l1!=NULL){
        
        temp=NULL;
        while(l1!=NULL && l1->data<=l2->data){
            temp=l1;
            l1=l1->next;
        }
        if(l1==NULL){
            break;
        }
        temp->next=l2;
        node * n=l1;
        l1=l2;
        l2=n;
    }
        
    temp->next=l2;
    return res;
}


int main(){
    node* head1=NULL;
    node* head2=NULL;
    int a[4]={1,3,5,15};
    int b[5]={2,4,6,8,12};
    for(int i=0; i<4; i++){
        insertAtTail(head1,a[i]);
    }
    for(int i=0; i<5; i++){
        insertAtTail(head2,b[i]);
    }
    print(head1);
    print(head2);
    node* newhead=mergetwo(head1,head2);
    print(newhead);

    return 0;
}