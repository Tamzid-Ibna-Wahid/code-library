#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


const int N = 2000010;

typedef long long item;
// struct item{
//     int m, c;
// };

struct segtree{
      
  int size;
  vector<item>values;
    
  item NEUTRAL_ELEMENT = INT_MIN;   // change 
    
  item merge(item a, item b) { return max(a,b); }// change 
  item single(int v) { return v; }
      
  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    // values.assign(2 * size , {INT_MAX,0}); 
    values.resize(2 * size);   // auto initialize with 0
  }
  
  void build(vector<long long> &a, int x,int lx,int rx){
    if(rx - lx == 1){
      if(lx < a.size()){
        values[x] = single(a[lx]);
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a , 2 * x+1 , lx , m);
    build(a , 2 * x+2 , m , rx);
     values[x] = merge(values[2*x+1],values[2*x+2]);
  }
  void build(vector<long long> &a){ build(a, 0, 0, size); }
  
  void set(int i , int v , int x , int lx , int rx){
    if(rx - lx == 1){
      values[x] = single(v);
      return;
    }
    int m = (lx + rx) / 2;
    if(i < m){
      set(i , v , 2 * x +1 , lx , m);
    }
    else{
      set(i , v , 2 * x + 2, m , rx);
    }
         values[x] = merge(values[2*x+1],values[2*x+2]);
    }
    void set(int i, int v){set(i , v, 0, 0, size);}
    
  item calc(int l, int r, int x, int lx, int rx){
    if(lx>=r || l>=rx) return NEUTRAL_ELEMENT;
    if(lx >= l && rx <= r) return values[x];
    int m = (lx + rx) / 2;
    item s1 = calc(l, r, 2 * x + 1, lx, m);
    item s2 = calc(l, r, 2 * x + 2, m, rx);
    return merge(s1,s2); 
  }
  item calc(int l, int r) { return calc(l, r, 0, 0, size); }
};


signed main(){

    fast_cin();
        
     int n; cin>>n;
        
    vector<long long>v(n);
    for(int i = 0; i<n; i++)cin>>v[i];
        
    segtree st;
    st.init(n);
    st.build(v);
       
    int x = st.calc(2, 4);  // [l, r)   and it is 0 based indexing
    
    cout<<x<<endl;
        
    return 0;
}