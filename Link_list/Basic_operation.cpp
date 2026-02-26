// array to ll

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
 
 int lengthogLL(node* head){
    int cnt = 0;
      node* temp = head;
      while(temp){
        temp = temp->next;
        cnt++;
      }
      return cnt;
 }

bool checkIfPresent(node* head , int val){
       node* temp = head;
      while(temp){
        if(temp->data == val)return true;
        temp = temp->next;
      }
      return false;
}

node* delete_head(node* head){
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
    
}


signed main(){

      std::vector<int> v = {2,1,3,8};
      
      node* head = convertArrtoLL(v);
      
      node* temp = head;
      
      while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
      }
      cout<<endl;
      


    // length of the LL
      cout<<lengthogLL(head)<<endl;
      
      
    //checkIfPresent
    cout<<checkIfPresent(head , 5)<<endl;
      
      
      
    

  

    return 0;
}