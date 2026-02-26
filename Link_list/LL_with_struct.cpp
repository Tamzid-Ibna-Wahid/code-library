#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node *next;
    
    node(int data1 , node *next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
    }
    
};

signed main(){

      int n = 5;
      int *m =&n;  // store address
      cout<<m<<endl;
      
      
      node x = node(5);
      cout<<x.data<<endl;
      cout<<x.next<<endl;


  

    return 0;
}