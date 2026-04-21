#ifndef ONLINE_JUDGE
#include "Siuuu.h"
#else
#define deb(x)

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;  // less ,less_equal , greater, greater_equal, cmp, *a.find_by_order() , order_of_key()
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;
#define endl "\n"
#define REPn(i,n) for(ll i = 0; i < n; i++) 
#define REPsn(i,s,n) for(ll i = s; i <= n; i++)
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define int long long
#define em emplace_back
#define mp make_pair 
#define pb push_back 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size()) 
#define INF 2000000000000000000
#endif

const ll mod = 1000000007;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}

std::vector<pair<int,int>>knight ={{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-2,-1}, {-2,1}};

const int N = 2000010;

typedef int item;
// struct item{
//     int m, c;
// };

struct segtree{
      
    item NEUTRAL_ELEMENT = 0;
    int size;
    vector<item>values;
    
    
    item merge(item a, item b) {
        return a + b;
    }
      
    item single(int v){
        return v;
    }
      
  
  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    // values.assign(2 * size , {INT_MAX,0}); 
    values.resize(2 * size);   // auto initialize with 0
  }
  
  
  
  void build(vector<int> &a, int x,int lx,int rx){
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
    
  void build(vector<int> &a){
    build(a, 0, 0, size);
  }
  
  
  
  
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

    void set(int i, int v){
      set(i , v, 0, 0, size);
    }

    
  
  item calc(int l, int r, int x, int lx, int rx){
    if(lx>=r || l>=rx) return NEUTRAL_ELEMENT;
    if(lx >= l && rx <= r) return values[x];
    int m = (lx + rx) / 2;
    item s1 = calc(l, r, 2 * x + 1, lx, m);
    item s2 = calc(l, r, 2 * x + 2, m, rx);
    return merge(s1,s2); 
  }
  
  item calc(int l, int r){
    return calc(l, r, 0, 0, size);
  }
  
  
  // finding the kth '1'
  item find(int k, int x, int lx, int rx){
    if(rx - lx == 1){
      return lx;
    }
    int m = (lx + rx)/2;
    int sl = values[2 * x +1];
    
    if(k < sl){
      return find(k, 2 * x + 1, lx, m);
    }
    else{
      return find(k - sl, 2 * x + 2, m, rx);
    }
  }
  
  item find(int k){
    return find(k, 0, 0, size);
  }
  
};

// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B

void siuuuuu(){
        
        int n, m;
        
        cin>>n>>m;
        
        vector<int>v(n);
        REPn(i,n)cin>>v[i];
        
          segtree st;
       st.init(n);
       st.build(v);
       
       
     
        
        
        while(m--){
            int t;
            cin>>t;
            
            if(t==1){
                int ind;
                cin>>ind;
                v[ind] ^= 1;
                st.set(ind,v[ind]);
            }
            else{
               int k;
               cin>>k;
               cout<<st.find(k)<<endl;
            }
        }
       
       







}




signed main(){

 #ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
 #endif


     fast_cin();
     cout << fixed;
     cout << setprecision(10);

    int tt;
                tt=1;
    // cin>>tt;  

   for(int i=1;i<=tt;i++){
        
    //cout<<"Case "<<i<<": ";
        
        siuuuuu();          
    }
  
    return 0;
}