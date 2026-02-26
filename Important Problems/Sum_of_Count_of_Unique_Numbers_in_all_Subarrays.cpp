#ifndef ONLINE_JUDGE
#include "Siuuu.h"
#else
#define deb(x)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

// Returns Sum of Count of Unique Numbers
// in all Subarrays
int countUniqueElements(vector<int> a)
{
    int n = a.size();

    int total_subarrays = n * (n + 1) / 2;

    // To store final answer
    int res = 0;

    // To store indexes of each element
    unordered_map<int, vector<int> > mp;

    // Iterate the array to store the index
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }

    // Iterate over the map to find the
    // contribution of each unique element
    for (auto x : mp) {

        // Stores the indexes of element x
        vector<int> arr = x.second;

        arr.push_back(n);

        // Stores the length of index array
        int len = arr.size();

        // To find contribution of element x
        // in the final answer
        int contribution = 0;

        // To store previous index of element x
        int p = -1;
        for (int j = 0; j < len; j++) {
            int index_difference = arr[j] - p - 1;
        
        // in the middle of 2 'x' element we count number of subarray where there is no x
            contribution += (index_difference * (index_difference + 1))/ 2;
            p = arr[j];
        }

        // Add contribution of each unique element
        // (total subarray - subarray that do not contain x)
        res = res + (total_subarrays - contribution);
    }

    return res;
}



void siuuuuu(){
        
        int n;
        cin>>n;
        
        vint v(n);
        REPn(i,n)cin>>v[i];
       
       map<int,int>m;
       
       for(int i = 0;i<n;i++){
         if(m[abs(v[i])]==0){
            if(v[i]<0){
                v[i] = -1*v[i];
            }            
         }
         else{
            if(v[i]>0){
                v[i] = -1*v[i];
            }
         }
            m[abs(v[i])] = (m[abs(v[i])]^1);
       }
       
     
     cout<<countUniqueElements(v)<<endl;
       

}

// gfg -> https://www.geeksforgeeks.org/dsa/sum-of-count-of-unique-numbers-in-all-subarrays/
//Problem -> https://codeforces.com/gym/104822/problem/G?csrf_token=4e62dcc42c228e412f7d6bc386072af8




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