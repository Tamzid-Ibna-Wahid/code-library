#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    public:    
    node(int data1 , node *next1){
        data = data1;
        next = next1;
    }
    public:
    node(int data1){
        data = data1;
        next = nullptr;
    }
    
};

 node* convertArrtoLL(vector<int>&v){
    node* head = new node(v[0]);
    node* mover = head;
    for(int i=1;i<v.size();i++){
        node* temp = new node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
 }
 
void print(node* head){
      node* temp = head;
      while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
      }
      cout<<endl;
}

node* insertHead(node* head, int val){
    node* temp = new node(val, head);
    return temp;
}

node* insertTail(node* head, int val){
    if(head == nullptr){
        return new node(val);
    }
    node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    node* newNode = new node(val);
    temp->next = newNode;
    return head;
    
}
node* insertPosition(node* head, int val, int k){
    if(head==nullptr){
        if(k==1){
            return new node(val);
        }
        else return head;
    }
    
    if(k==1){
         node* temp = new node(val, head);
        return temp;
    }
    int cnt = 0;
    node* temp = head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==(k-1)){
            node* x = new node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

node* insertBeforeElement(node* head, int val, int element){
    if(head==nullptr){
        return nullptr;
    }
    
    if(head->data==element){
         node* temp = new node(val, head);
        return temp;
    }
    node* temp = head;
    while(temp->next!=nullptr){
        if(temp->next->data == element){
            node* x = new node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}


signed main(){

      std::vector<int> v = {2,1,3,8};
      
      node* head = convertArrtoLL(v);
      
       
    //inserting head
    head = insertHead(head, 100);
    print(head);
    
    // inserting last
    head = insertTail(head,302);
    print(head);
    
    // insert in kth position
    head = insertPosition(head, 345, 4);
    print(head);
    
    // inserting an value before the element 3
    head = insertBeforeElement(head , 555, 3);
    print(head);
    
    
    
    
    
   
    
    

  

    return 0;
}