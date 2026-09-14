#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
 // binomial coefficient O(r)  it is work for small n and r (20 - 30)
int nCr(int n, int r) {
    int sum = 1;
    for (int i = 1; i <= r; i++) {
        sum = sum * (n - r + i);
        sum /= i;
    }
    return sum;
}


// YouKnowWho
int f[N], inv[N], finv[N];
void prec() {
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = 1LL * i * f[i - 1] % mod;
  inv[1] = 1;
  for (int i = 2; i < N; i++ ) {
    inv[i] = (-(1LL * mod / i) * inv[mod % i] ) % mod;
    inv[i] = (inv[i] + mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < N; i++) finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}
int nCr(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return 1LL * f[n] * finv[n - r] % mod * finv[r] % mod;
}
int nPr(int n, int r){
  if (n < r || n < 0 || r < 0) return 0;
  return 1LL * f[n] * finv[n - r] % mod;
}




// ChatGPT

int fact[N], finv[N];
int modExp(int a, int n, int M) {
    int res = 1;
     a %= M;
    while (n > 0) {
        if (n & 1) res = (res * a) % M;
        a = (a * a) % M;
        n >>= 1;
    }
    return res;
}
int modInverse(int a, int M) {
    return modExp(a, M - 2, M);
}
 
void prec() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
    finv[N - 1] = modInverse(fact[N - 1], mod);
    for (int i = N - 1; i >= 1; i--) finv[i - 1] = 1LL * finv[i] * i % mod;
}

int nCr(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return 1LL * fact[n] * finv[r] % mod * finv[n - r] % mod;
}
int nPr(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return 1LL * fact[n] * finv[n - r] % mod;
}









// my previous one
vector<int>fact(N);
void factorial(){
    fact[0]=1;
    for(int i=1;i<N;i++) fact[i] = mod_mul(fact[i-1], i);
}
int nCr(int n, int r) {
   if (n < r || n < 0 || r < 0) return 0;
    return mod_mul(inv(fact[n-r]), mod_mul(fact[n],inv(fact[r])));
}
int nPr(int n, int r){
    if (n < r || n < 0 || r < 0) return 0;
    return mod_mul(fact[n], inv(fact[n - r]));
}

int main(){


    
    return 0;
}