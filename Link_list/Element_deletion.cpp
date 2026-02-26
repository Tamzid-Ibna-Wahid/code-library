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
 


node* removeHead(node* head){
    if(head == nullptr)return head;
    node* temp = head;
    head = head->next;
    free(temp);
    return head;   
}

node* removeTail(node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    
    node* temp = head;
    while(temp->next->next!=nullptr) temp = temp->next;
    
    free(temp->next);
    temp->next = nullptr;
    
    return head;
}

node* remove_Kth_element(node* head, int k){
   if(head == nullptr) return head;  // it is nullptr
   if(k == 1){
     node* temp = head;
    head = head->next;
    free(temp);
    return head;   
    }
    int cnt = 0;
    node* temp = head;
    node* prv = nullptr;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prv->next = prv->next->next;
            free(temp);
            break;
        }
        prv = temp;
        temp = temp->next;
    }
    return head;
}

node* removeElement(node* head, int val){
   if(head == nullptr) return head;
   if(head->data == val){
     node* temp = head;
    head = head->next;
    free(temp);
    return head;   
    }
    node* temp = head;
    node* prv = nullptr;
    while(temp!=nullptr){
        if(temp->data==val){
            prv->next = prv->next->next;
            free(temp);
            break;
        }
        prv = temp;
        temp = temp->next;
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


signed main(){

      std::vector<int> v = {2,1,3,8};
      
      node* head = convertArrtoLL(v);
      
      
    //   delete the head
          node* new_head = removeHead(head);
          cout<<new_head->data<<endl;
          
          
   
    // delete lail    
     head = removeTail(head);
    print(head);
    
    
    // delete kth_element
       
       head = remove_Kth_element(head,4);
       print(head); 
       
       
    // remove_element;
       head = removeElement(head,3);
       print(head);
       
       
   
    
    
   
    
    

  

    return 0;
}