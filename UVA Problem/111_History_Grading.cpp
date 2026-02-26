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




int get_lis(vint &arr) {
    if (arr.empty()) return 0;
    vint dp;
    dp.push_back(arr[0]);
    for (int i = 1; i < (int)arr.size(); i++) {
        if (arr[i] > dp.back()) {
            dp.push_back(arr[i]);
        } else {
            int pos = lower_bound(all(dp), arr[i]) - dp.begin();
            dp[pos] = arr[i];
        }
    }
    return dp.size();
}

void siuuuuu() {

    int n;
    if (!(cin >> n)) return;

    while (true) {

        // correct_pos[i] = correct rank of event i
        vint correct_pos(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> correct_pos[i];
        }

        string line;
        // getline(cin, line); // consume newline
        cin.ignore();

        while (getline(cin, line)) {

            if (line.empty()) continue;

            stringstream ss(line);
            vint temp;
            int x;
            while (ss >> x) temp.push_back(x);

            // new test case starts
            if ((int)temp.size() == 1) {
                n = temp[0];
                break;
            }

            // build LIS array
            vint seq(n + 1);
            for (int i = 1; i <= n; i++) {
                int student_rank = temp[i - 1];
                seq[student_rank] = correct_pos[i];
            }

            vint final_seq;
            for (int i = 1; i <= n; i++) final_seq.push_back(seq[i]);

            cout << get_lis(final_seq) << endl;
        }

        if (cin.eof()) break;
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