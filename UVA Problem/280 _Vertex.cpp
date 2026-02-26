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

const ll mod = 1e9 + 7;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}

std::vector<pair<int,int>>knight ={{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-2,-1}, {-2,1}};

const int N = 105;







void siuuuuu(){
    
    int edge[N][N];
    
        
        int n;
    while(true){
        
         cin>>n;
              
         if(n==0)break;
         
    for(int i=0;i<=n;i++){
        for(int j = 0;j<=n;j++)edge[i][j] = 0;
    }
                
        while(true){
            int u;
            cin>>u;
            if(u==0)break;
            
            while(true){
                int v;
                cin>>v;
                if(v==0)break;
                edge[u][v] = 1;
            }
        }
        
        
        for(int k=1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    edge[i][j] = edge[i][j] || (edge[i][k] && edge[k][j]);
                }
            }
        }
        
        
        
            int q;
            cin>>q;
     
            while(q--){
                int x;
                cin>>x;
                
                vector<int>ans;
                
                for(int i = 1;i<=n;i++){
                    if(!edge[x][i])ans.em(i);
                }
                
                  cout << sz(ans);
            for(auto &it : ans) cout << " " << it;
            cout << endl;
            
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