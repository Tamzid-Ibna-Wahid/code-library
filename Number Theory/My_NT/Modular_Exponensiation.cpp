#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
// a ^ n % M  =  ((a % M) ^ n) % M
 // calculate a^n % M
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



/*
 (a^b) % M = (a ^ (b % phi(M))) % M
 if(M=prime) phi(M) = M-1;
*/

 int Big_power(int a,int b,int c,int M){
     return  modExp(a ,modExp(b ,c ,M-1), M);
 }



int main(){
    

    return 0;
}