
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int modExp(int a, int n, int M) {
    int res = 1;
     a %= M;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        n >>= 1;
    }
    return res;
}
 // calculate a^n % M  when a<= 2^1024 (a is big)
int modExp_for_large_power(int a, int n, int M) {

    a=modExp(2,1024,M);
      
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        n >>= 1;
    }
    return res;
}




signed main(){

    fast_cin();
            
        
        
        
    return 0;
}