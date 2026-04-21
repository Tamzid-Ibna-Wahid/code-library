#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e8 + 10;

bitset<N> isComposite;   // 0 = prime, 1 = composite
vector<int> prime;    // 1e8 porjonto somvob

void bit_sieve() {
    isComposite[0] = isComposite[1] = 1;
    for (int i = 2; i * i < N; i++) {
        if (!isComposite[i]) {
            for (int j = i * i; j < N; j += i) {
                isComposite[j] = 1;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (!isComposite[i])
            prime.push_back(i);
    }
}

signed main(){

    fast_cin();
    
    
        bit_sieve();
        
        
    return 0;
}