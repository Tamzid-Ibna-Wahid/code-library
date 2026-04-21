#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
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

int main(){

    
    return 0;
}