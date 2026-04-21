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
#define vint vector<int>
#define vpr vector<pr>
#define vvint vector<vector<int>>
#define pr pair<int, int>
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

const int N = 5e5 + 10;

struct Mat {
  int n, m;
  vector<vector<int>> a;
  Mat() { }
  Mat(int _n, int _m) {n = _n; m = _m; a.assign(n, vector<int>(m, 0)); }
  Mat(vector< vector<int> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
  inline void make_unit() {
    assert(n == m);
    for (int i = 0; i < n; i++)  {
      for (int j = 0; j < n; j++) a[i][j] = i == j;
    }
  }
  inline Mat operator + (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
      }
    }
    return ans;
  } 
  inline Mat operator - (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
      }
    }
    return ans;
  }
  inline Mat operator * (const Mat &b) {
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < b.m; j++) {
        for(int k = 0; k < m; k++) {
          ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
        }
      }
    }
    return ans;
  }
  inline Mat pow(long long k) {
    assert(n == m);
    Mat ans(n, n), t = a; ans.make_unit();
    while (k) {
      if (k & 1) ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }
  inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
  inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
  inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
  inline bool operator == (const Mat& b) { return a == b.a; }
  inline bool operator != (const Mat& b) { return a != b.a; }
};




void siuuuuu(){
        
        int a, b, c;
        cin>>a>>b>>c;
        
        vvint x = {{0, 1}, {1, 1}}, y = {{a, b}};
        
        Mat A(x), B(y);
        
        
        Mat D = A.pow(c);
        
        D = B * D;
        
        
        cout<<D.a[0][0]<<endl;
        
        
       
       
       
       // nth fibonacci Number in log(n)
        
        int n;
        cin>>n;
         Mat A(2,2);
         
         
         // {fn+1, fn}
         // {fn, fn-1}
         
         // {1, 1}  
         // {1, 0}
         
         // 0th 1th 2th 3th 4th 5th 
         //  0  1   1   2   3   5   
         
         A.a[0][0] = A.a[0][1] = A.a[1][0] = 1;
         A.a[1][1] = 0;
         
         
       A = A.pow(n);
       
       cout<<A.a[0][1]<<endl; 
        
        
       
       







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
    cin>>tt;  

   for(int i=1;i<=tt;i++){
        
    //cout<<"Case "<<i<<": ";
        
        siuuuuu();          
    }
  
    return 0;
}