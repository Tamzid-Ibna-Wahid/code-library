#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
struct segtree{
  
  int size;
    vector<int>tree;
  
  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    tree.assign(2 * size , INT_MAX);   // c
  }
  
  
  void build(vector<int> &a, int x,int lx,int rx){
    if(rx - lx == 1){
      if(lx < a.size()){
        tree[x] = a[lx];
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a , 2 * x+1 , lx , m);
    build(a , 2 * x+2 , m , rx);
    tree[x] = min(tree[2 * x +1],tree[2 * x +2]);    // c
  }
    
  void build(vector<int> &a){
    build(a, 0, 0, size);
  }
  
  
  
  
  void set(int i , int v , int x , int lx , int rx){
    if(rx - lx ==1){
      tree[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if(i < m){
      set(i , v , 2 * x +1 , lx , m);
    }
    else{
      set(i , v , 2 * x + 2, m , rx);
    }
    tree[x] = min(tree[2 * x + 1] , tree[2 * x + 2]);   // c
    }
    
    
    void set(int i, int v){
      set(i , v, 0, 0, size);
    }
    
  
  int calc(int l, int r, int x, int lx, int rx){
    if(lx>=r || l>=rx) return INT_MAX;
    if(lx >= l && rx <= r) return tree[x];
    int m = (lx + rx) / 2;
    int s1 = calc(l, r, 2 * x + 1, lx, m);
    int s2 = calc(l, r, 2 * x + 2, m, rx);
    return min(s1,s2);                         // c
  }
  
  int calc(int l, int r){
    return calc(l, r, 0, 0, size);
  }
  
};


int main(){

      int n,m;
       cin>>n>>m;
       
       vector<int>v(n);
       
       REPn(i,n)cin>>v[i];
       
       
       segtree st;
       st.init(n);
       
       st.build(v);
       deb(st.tree);
       
       while(m--){
        int op;
        cin>>op;
        if(op==1){
          int ind , val;
          cin>>ind>>val;
        st.set(ind,val);
        }
        else{
          int l,r;
          cin>>l>>r;
          cout<<st.calc(l,r)<<endl;
        }
       }
       

    
    return 0;
}