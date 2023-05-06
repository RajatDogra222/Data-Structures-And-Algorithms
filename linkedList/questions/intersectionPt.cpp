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

void makeIntersec(node* &head1,node* &head2,int pos){
     node* temp1=head1;
     node* temp2=head2;

     int count=1;
     while(count!=pos){
         temp2=temp2->next;
         count++;
     }
     node* point=temp2;

     while(temp1->next!=NULL){
         temp1=temp1->next;
     }
     temp1->next=point;
}

int  intersec(node* head1,node* head2){
    int l1=length(head1);
    int l2=length(head2);
    node* temp1=NULL;
    node* temp2=NULL;
    int pos=0;
    if(l1>=l2){
        temp1=head1;
        temp2=head2;
        pos=l1-l2;
    }
    else{
        temp1=head2;
        temp2=head1;
        pos=l2-l1;
    }

    int count=1;
    while(count<=pos && temp1!=NULL){
        temp1=temp1->next;
        count++;
    }

    while(temp1!=NULL && temp2!=NULL){

        if(temp1->next==temp2->next){
            return temp1->next->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}

node* intersecNode(node* head1,node* head2){
    if(head1==NULL || head2==NULL){
        return NULL;
    }
    node* l1=head1;
    node* l2=head2;

    while(l1!=l2){
       
       l1=l1==NULL?head2:l1->next;
       l2=l2==NULL?head1:l2->next;
    }
    return l1;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    int a[3]={1,3,5};
    int b[5]={2,4,6,8,12};
    for(int i=0; i<3; i++){
        insertAtTail(head1,a[i]);
    }
    for(int i=0; i<5; i++){
        insertAtTail(head2,b[i]);
    }
    print(head1);
    print(head2);
    makeIntersec(head1,head2,5);
    print(head1);
    print(head2);
    // cout<<intersec(head1,head2);
    node* interNode=intersecNode(head1,head2);
    cout<<interNode->data<<endl;

    return 0;
}