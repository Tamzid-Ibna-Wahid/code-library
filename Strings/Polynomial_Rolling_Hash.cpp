#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const ll mod = 1e9+7;


/*
This is needed for Rabin_karp
*/

int getHash(string &str){
    int value = 0;
    int p = 31;    // power should be greater then the charecter set and need to be prime
    int p_power = 1;

    for(auto &ch : str){
        value = (value + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }
    return value;
}


const ll mod1 = 1000000007;
const ll mod2 = 1000000009;

const ll p1 = 31;
const ll p2 = 37;

map<pair<ll,ll>, int> cnt;

pair<int, int> doubleHash(string &str){
    ll hash1 = 0, hash2 = 0;
    ll pow1 = 1, pow2 = 1;

    for (auto &ch : str){
        int val = (ch - 'a' + 1);
        hash1 = (hash1 + val * pow1) % mod1;
        hash2 = (hash2 + val * pow2) % mod2;
        
        pow1 = (pow1 * p1) % mod1;
        pow2 = (pow2 * p2) % mod2;
        
        cnt[{hash1, hash2}]++;
    }
    return {hash1, hash2};
}



signed main() {
   
   string str;
   cin>>str;

   cout<<"string : "<<str<<endl;
   cout<<"Hash Value : "<<getHash(str)<<endl;

    return 0;
}
