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


bool search(node* head,int key){

    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deletion(node* &head,int val){
    
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }


    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int length(node* head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

node* reverse(node* &head){
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


node* recursiveRev(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node *rechead=recursiveRev(head->next);
    head->next->next=head;
    head->next=NULL;
    return rechead;
}

node* reverseKnode(node* &head,int k){
   
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k ){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    
   
    if(nextptr!=NULL){
        int l=length(nextptr);
        if(l>=k){
            head->next=reverseKnode(nextptr,k);
        }
        else{
            head->next=nextptr;
        }
    }

    return prevptr;
}

void makecycle(node* &head,int pos){
    node* temp=head;
    node* cycleNode;
    int count=1;
    while(temp->next!=NULL){
          if(count==pos){
              cycleNode=temp;
          }
          temp=temp->next;
          count++;
    }
    temp->next=cycleNode;
}

bool detectCycle(node* head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;
    do
    {
      slow=slow->next;
      fast=fast->next->next;
    } while (slow!=fast);
    fast=head;

    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
}

node* appendKNodes(node* &head,int k){
    node* newTail;
    node* newhead;
    node* temp=head;
    int l=length(head);
    k=k%l;
    int count=1;
    while(temp->next!=NULL){
           if(count==l-k){
               newTail=temp;
           }
           if(count==l-k+1){
               newhead=temp;
           }
           temp=temp->next;
           count++;
    }
    newTail->next=NULL;
    temp->next=head;

    return newhead;
}

void print(node* head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node *head=NULL;
    int a[8]={1,2,3,4,5,6,7,8};
    for(int i=0; i<8; i++){
        insertAtTail(head,a[i]);
    }
    print(head);
    node* newhead=reverseKnode(head,3);
    print(newhead);
    // makecycle(head, 3);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;
    // print(head);
    // node* newhead=appendKNodes(head,2);
    // print(newhead);

    

 return 0;
}