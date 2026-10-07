#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;

#define v2d  vector<vector<int>>
v2d matrixMult(v2d &a, v2d &b){
  int m = a.size(), n = a[0].size(), l = b[0].size();
  v2d ans(m, vector<int> (l));
  for(int i = 0; i < m; i++){
    for(int j = 0; j < l; j++){
      for(int k = 0; k < n; k++){
        ans[i][j] += a[i][k] * b[k][j] % mod;
        ans[i][j] %= mod;
      }
    }
  }
  return ans;
}

v2d matrixExpo(v2d v, int p){
  int n = v.size();
  v2d ans(n, vector<int>(n));
  for (int i = 0; i < n; i++) ans[i][i] = 1;  
  for(; p; p >>= 1, v = matrixMult(v, v)){
    if(p&1)ans = matrixMult(ans, v);
  }
  return ans;
}

v2d fib_base = {{1, 1}, {1, 0}};  //for Fibonacci number
 // A^n =
    //
    // | F(n+1)  F(n)   |
    // | F(n)    F(n-1) |

int main() {

    ll n;
    cin >> n;

    v2d ans = matrixExpo(fib_base, n);

    cout << ans[0][1] << '\n';

    return 0;
}