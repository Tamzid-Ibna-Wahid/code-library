#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)



int binMultiply(int a, int b, int M) {
    int res = 0;
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return res;
}

// whem M<=10^18  (M is big)
int modExp_for_big_mod(int a, int n, int M) {
    int res = 1;
    while (n > 0) {
        if (n % 2 != 0) {
            res = binMultiply(res, a, M);
        }
        a = binMultiply(a, a, M);
        n >>= 1;
    }
    return res;
}



signed main(){

    fast_cin();
        
        
        
        
        
    return 0;
}