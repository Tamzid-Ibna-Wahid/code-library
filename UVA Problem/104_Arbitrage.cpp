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
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int N = 5e5 + 10;

        int n;

vector<int> f(int s, vector<vector<double>>&v){
   
   queue<pair<int, double>>q;
   q.push({s, 1.0});
   
   vector<int>ans;
   vvint vis(n, vint(n, 0));
   vis[s][s] = 1;
   vint par(n);
      
   while(!q.empty()){
      auto it = q.front();
      int current_node = it.fi;
      double  p = it.se;
      q.pop();
      
      for(int i = 0;i<n;i++){
         if(i==s){
            if(p*v[current_node][i] - 1.00 >= 0.01){
               ans.pb(s);
               while(current_node!=s){
                  ans.pb(current_node); current_node = par[current_node];
               }
               ans.pb(s);
               return ans;
            }            
         }
         else if(current_node==i)continue;
         else if(!vis[current_node][i]){
             q.push({i, p*v[current_node][i]});
             par[i] = current_node; 
             vis[current_node][i] = 1;
             vis[i][current_node] = 1;
         }
      }
   }
   return ans;
}





void siuuuuu(){
       
      
       while(cin>>n){
         vector<vector<double>> rate(n, vector<double>(n));
         
         for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
               if(i==j)rate[i][j] = 1.0;
               else cin>>rate[i][j];
            }
         }
         
         
          // dp[k][i][j] = best rate from i to j using exactly k steps
        vector<vector<vector<double>>> dp(n + 1,
            vector<vector<double>>(n, vector<double>(n, 0.0)));

        // parent[k][i][j] = previous node before j
        vector<vector<vector<int>>> parent(n + 1,
            vector<vector<int>>(n, vector<int>(n, -1)));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = rate[i][j];
                parent[1][i][j] = i;
            }
        }
        
        
         bool found = false;
        int step = -1, start = -1;
        
        for (int k = 2; k <= n && !found; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int m = 0; m < n; m++) {
                        double val = dp[k - 1][i][m] * rate[m][j];
                        if (val > dp[k][i][j]) {
                            dp[k][i][j] = val;
                            parent[k][i][j] = m;
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                if (dp[k][i][i] > 1.01) {   // arbitrage found
                    found = true;
                    step = k;
                    start = i;
                    break;
                }
            }
        }
        
        if (!found) {
            cout << "no arbitrage sequence exists\n";
            continue;
        }
        
         // reconstruct path
        vector<int> path(step + 1);
        path[step] = start;
        for (int k = step; k > 0; k--) {
            path[k - 1] = parent[k][start][path[k]];
        }
        
        
         for (int i = 0; i <= step; i++) {
            if (i) cout << " ";
            cout << path[i] + 1; 
        }
        cout << endl;

        
        
        
        
         
       } 
       
       
       







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
    // cin>>tt;  

   for(int i=1;i<=tt;i++){
        
    //cout<<"Case "<<i<<": ";
        
        siuuuuu();          
    }
  
    return 0;
}