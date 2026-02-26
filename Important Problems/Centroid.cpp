#ifdef LOCAL
#include "Siuuu.h"
#else
#define deb(x)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // less ,less_equal , greater, greater_equal, cmp, *a.find_by_order() , order_of_key()
template <typename T> using orderedmulti_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;
#define endl "\n"
#define vint vector<int>
#define vpr vector<pr>
#define vvint vector<vector<int>>
#define pr pair<int, int>
#define REPn(i,n) for(ll i = 0; i < n; i++) 
#define REPsn(i,s,n) for(ll i = s; i <= n; i++)
#define print(arr) for(auto &x: arr)cout<<x<<" ";endl;
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
#define sum_all(v) accumulate(all(v), 0ll)
#define sz(x) ((ll)(x).size()) 
#define INF 2000000000000000000
#endif

const ll mod = 1e9 + 7;

#define _log2(n)   31 - __builtin_clz(n)
#define pop_count(n)   __builtin_popcountll(n)
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}

std::vector<pair<int,int>>knight = {{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-2,-1}, {-2,1}};
std::vector<pair<int, int>>movement = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

const int N = 5e5 + 10;




vector<int> Centroid(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> centroid;
        vector<int> size(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                size[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        size[u] += size[v];
                        if (size[v] > n / 2) is_centroid = false;
                }
                if (n - size[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}




void siuuuuu(){
    
/* Given a tree. i have to remove one edge and add one edge on tree and have to make
   a tree which has one centroid. 
*/ 
       
       
         int n;
         cin>>n;
         
        vector<vector<int>>g(n);
        
        for(int i = 0;i<n-1;i++){
            int u, v;
            cin>>u>>v;
            u--;
            v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        
        vector<int>c = Centroid(g);
      // a tree can have one or two centroid
        
        
        // if centroid is one then remove any edge and add the same edge
        if(sz(c)==1){   
            cout<<1<<" "<<g[0][0]+1<<endl; 
            cout<<1<<" "<<g[0][0]+1<<endl;
        }
        // remove the edge between one centroid and his child. then connect the child 
        // with another centroid
        else{
            for(auto &child : g[c[1]]){
                if(child!=c[0]){
                    cout<<c[1]+1 <<" "<<child+1<<endl;
                    cout<<child+1<<" "<<c[0]+1<<endl;
                    return;
                }
            }
        }
        


// https://codeforces.com/problemset/problem/1406/C



}




signed main(){

  #ifdef LOCAL
  freopen("Error.txt", "w", stderr);
  #endif


     fast_cin();
     cout << fixed;
     cout << setprecision(10);

    int tt;
                tt=1;
    cin>>tt;  

   for(int i=1;i<=tt;i++){
        
    //cout<<"Case "<<i<<": ";
        
        siuuuuu();          
    }
  
    return 0;
}