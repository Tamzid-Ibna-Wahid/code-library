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

const int mod = 1000000007; // 998244353

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

int up(const string &a, const vint &d){
    string t;
    for(int i = 0;i<sz(a);i++){
        int digit = a[i] - '0';
        if(binary_search(all(d), digit)){
            t.pb(a[i]);
        }
        else{
            int j = i;
            while(j>=0 && d[sz(d)-1] <= a[j]-'0')j--;
            if(j<0){
                t.clear();
                while(sz(t) != sz(a)+1)t.pb((char)(d[0] + '0'));
                if(d[0]==0 && sz(d)>1)t[0] = (char)(d[1] + '0');
                return stoll(t);
            }
            else{
                while(sz(t)!=j)t.pop_back();
                auto it = upper_bound(all(d), a[j]-'0');
                t.pb((char)(*it + '0'));
                while(sz(t)<sz(a))t.pb((char)(d[0] + '0'));
                return stoll(t);
            }
        }
    }
    return stoll(t);
}

int down(const string &a, const vint &d){
    string t;
    for(int i = 0;i<sz(a);i++){
        int digit = a[i] - '0';
        if(binary_search(all(d), digit)){
            t.pb(a[i]);
        }
        else{
            int j = i;
            while(j>=0 && d[0] >= a[j]-'0')j--;
            if(j<0){
                t.clear();
                while(sz(t) != sz(a)-1)t.pb((char)(d[sz(d)-1] + '0'));
                if(t.empty())return -1;
                return stoll(t);
            }
            else{
                while(sz(t)!=j)t.pop_back();
                auto it = lower_bound(all(d), a[j]-'0');
                --it;
                t.pb((char)(*it + '0'));
                while(sz(t)<sz(a))t.pb((char)(d[sz(d)-1] + '0'));
                
                return stoll(t);
            }
        }
    }
    return stoll(t);
}


void siuuuuu(){
    
        // find number b so that abs(a-b) is minimum
         
         string a;   // number a
         int n;     // number of allowed digit
         cin>>a>>n;
         
         vint d(n);         // allowed digits
         REPn(i,n)cin>>d[i];  
         
         int x = stoll(a);
         
         int y = up(a, d); 
         int z = down(a, d);
         
         
        int ans = abs(y-x);
        if(z>=0)ans = min(ans, x - z);
        
         
         cout<<ans<<endl;
       

     // https://codeforces.com/contest/2228/problem/C2



}




signed main(){

  #ifdef LOCAL
  freopen("Error.in", "w", stderr);
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