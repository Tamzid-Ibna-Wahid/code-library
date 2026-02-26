#ifndef ONLINE_JUDGE
#include "Siuuu.h"
#else
#define deb(x)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // less ,less_equal , greater, greater_equal, cmp, *a.find_by_order() , order_of_key()
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

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}

std::vector<pair<int,int>>knight ={{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-2,-1}, {-2,1}};

const int N = 5e5 + 10;

class dsu{

public:
    vector<int> parent, size, rank;
    
public:
    dsu(int n){
        for(int i = 0;i<=n;i++){
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }
    int findpar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }
    
    void unionSize(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
        
        if(pu == pv) return;
        
        if(size[pu] < size[pv]){ 
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        
    }
    
};



void siuuuuu(){
        
        int n, m;
        cin>>n>>m;
        
         vector<pair<int,pair<int,int>>> edge;
        
        REPn(i,m){
            int u, v, w;
            cin>>u>>v>>w;
            edge.pb({w, {u, v}});
        }
                
        
        if(m<n-1){
            cout<<"No way"<<endl;
            return;
        }
        
        sort(all(edge));
        
        int n1, n2, ww;
        vint tt;  // for a specific edge what is the MST
        
        for(int i = 0;i<m;i++){
            
            ww = edge[i].fi;
            n1 = edge[i].se.fi;
            n2 = edge[i].se.se;
        
        
        dsu d(n);
        d.unionSize(n1, n2);
        
        int sum = ww;
        int cnt_edge = 1;
        
        for(auto &it:edge){
             int weight = it.fi;
            int u = it.se.fi;
            int v = it.se.se;
            if(d.findpar(u) != d.findpar(v)){
                sum += weight;
                d.unionSize(u, v);
                cnt_edge++;
            }       
        }
            
        if(cnt_edge==n-1)tt.pb(sum);
        }
        
        sort(all(tt));
        
       if(sz(tt)==n-1){
          cout<<"No second way"<<endl;
       }
       else if(sz(tt)==0){
         cout<<"No way"<<endl;
       }
       else{
            cout<<tt[n-1]<<endl;     //0 to n-2 all are best. n-1 is the second best
       }
        
}



signed main(){

    int tt;
                tt=1;
    cin>>tt;  

   for(int i=1;i<=tt;i++){
        
    cout<<"Case #"<<i<<" : ";
        
        siuuuuu();          
    }
  
    return 0;
}

//https://vjudge.net/contest/745010#problem/B