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

const ll mod = 998244353;

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

const int N = 2e5 + 10;



// calculate a^n
int binExp(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}


int sum_of_digit_from_0_to_n(int n){
    
        int total_number = n + 1;    
        int range = 10;
        int mx_digit = log10(total_number-1) + 1;
        int ans = 0;
        for(int i = 1;i <= mx_digit;i++){
            int e = (total_number%range);
            int p = range/10;
            ans += 45 * (total_number/range) * p;
            int small_block = e/p;
            ans += (small_block*(small_block-1)/2) * p;  // 0 theke suru tai small_block*(small_block-1)/2
            ans += small_block * (e%p);
            range*=10;
        }
        return ans;
}


void siuuuuu(){

         int n;
         cin>>n;

        int t = n;
        
        
        int d = 9;
        int i = 1;
        
        // k digit diye max kon number porjonto jaoya jay
        while(t-d*i>=0){
            t -= d*i;
            i++;
            d*=10;
        }
        
        int f = binExp(10, i-1) - 1 + t/i + 1;  // f hocche oi number jeitar kisu part ans e contribute kore
        t %= i; 
        
        int total_number = f;  // 0  to f - 1;

        int ans = 0;
        
        string extra = to_string(f);
        for(int i = 0;i<t;i++){
            ans += extra[i] - '0';
        }
        
        cout<<ans + sum_of_digit_from_0_to_n(f-1)<<endl;
        
        
// https://codeforces.com/problemset/problem/2132/D













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
