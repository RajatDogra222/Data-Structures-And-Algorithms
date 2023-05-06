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


node* addNum(node* head1,node* head2){
    node* dummy=new node(0);
    node* temp=dummy;
    int carry=0;
    while(head1!=NULL || head2!=NULL || carry){
          int sum=0;
          if(head1!=NULL){
              sum+=head1->data;
              head1=head1->next;
          }
          
          if(head2!=NULL){
              sum+=head2->data;
              head2=head2->next;
          }

          sum+=carry;
          carry=sum/10;
          node* n=new node(sum%10);
          temp->next=n;
          temp=temp->next;
    }

    return dummy->next;
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    int a[3]={2,4,3};
    int b[4]={5,6,7,9};
    for(int i=0; i<3; i++){
        insertAtTail(head1,a[i]);
    }
    for(int i=0; i<4; i++){
        insertAtTail(head2,b[i]);
    }
    print(head1);
    print(head2);
    node* newhead=addNum(head1,head2);
    print(newhead);
    return 0;
}