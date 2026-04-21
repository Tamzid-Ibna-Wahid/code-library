#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

template <class T>
struct BIT { //1-indexed
  int n; 
  vector<T> t;
  BIT() {}
  
  BIT(int _n) {
    n = _n; 
    t.assign(n + 1, 0);
  }
  T query(int i) {
    T ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, T val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};


int32_t main() {
    
    int n;
    cin>>n;
    
    vector<int>a(n+1);
    for(int i = 1;i<=n;i++)cin>>a[i];    // first do it 1 based indexing
    
    BIT<int> bit(n);
  
  // Build   
    for(int i = 1;i<=n;i++){
      bit.upd(i, a[i]);
    }

    // query sum from 1 to 3
    cout << bit.query(3) << "\n";      // 1+2+3 = 6

    // query sum in range [2,4]
    cout << bit.query(2, 4) << "\n";   // 2+3+4 = 9

    // update: add +10 at index 3
    bit.upd(3, 10);

    // query sum [1,3] again
    cout << bit.query(3) << "\n";      // (1+2+13) = 16
    
    
    // Note
    // if we use upd(l, r, val) fundtion we can not use query(l, r) operation, but we can 
    // use query(i) operation. because after upd operation the BIT is storing a difference array, 
    // not the prefix sums anymore.

  return 0;
}

