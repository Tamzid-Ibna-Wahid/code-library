#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"

#define REPn(i,n) for(ll i = 0; i < n; i++) 
#define REPsn(i,s,n) for(ll i = s; i <= n; i++)

#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define int long long
#define em emplace_back
#define mp make_pair 
#define pb push_back 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size()) 
#define INF 2e18
const ll mod = 1e9+7;


ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}

std::vector<pair<int,int>>knight ={{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-2,-1}, {-2,1}};

const int N = 2e5+10;




void siuuuuu(){
   
      int n,k;
      cin>>n>>k;
      vector<int>v(n);
      REPn(i,n)cin>>v[i];

      multiset<int>st;
      int res = 0;
      int l=0;

      for(int i=0;i<n;i++){
        st.insert(v[i]);

        while(*st.rbegin()-*st.begin()>k){
            st.erase(st.find(v[l]));
            l++;
        }
        res += (i-l+1);
    }
    cout<<res;









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

    while(tt--){

        siuuuuu();          
    }
  


    return 0;
}

// https://mirror.codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F