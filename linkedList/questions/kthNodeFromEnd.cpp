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
// void removeKthele(node* &head,int k){
//     int l=length(head);
//     if(l==k){
//         node* todelete=head;
//         head=head->next;
//         delete todelete;
//         return;
//     }
//     node* temp=head;
//     int count=1;
//     while(temp!=NULL && count!=l-k){
//         count++;
//         temp=temp->next;
//     }
//     node* todelete=temp->next;
//     temp->next=temp->next->next;
//     delete todelete;
// }

node* removeKthele(node* head,int k){
    node* dummy=new node(0);
    dummy->next=head;
    node* fast=dummy;
    node* slow=dummy;
    int count=0;
    while(count<k){
        fast=fast->next;
        count++;
    }
    if(fast->next==NULL){
        node* todelete=slow->next;
        head=head->next;
        delete todelete;
        return head;
    }

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    node* todelete=slow->next;
    slow->next=slow->next->next;
    delete todelete;

    return head;

}


int main(){
    node* head=NULL;
    int a[7]={1,2,3,4,5,6,7};
    for(int i=0; i<7; i++){
        insertAtTail(head,a[i]);
    }
    print(head);

    node* newHead= removeKthele(head,1);
    print(newHead);
    return 0;
}