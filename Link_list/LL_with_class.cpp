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

signed main(){
      
      node *x = new node(5);
      
      cout<<x->data<<endl;
      cout<<x->next<<endl;


  

    return 0;
}