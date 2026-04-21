#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

struct HashV{
  int n;
  int base = 131482; 
  int M1 = 1e9 + 7, M2 = 1e9 + 9;
  vector<int> v, pw1, pw2, ha1, ha2;
  
  HashV(vector<int> v) : v(v){
    n = v.size() - 1;
    pw1.resize(n + 1); pw2.resize(n + 1);
    ha1.resize(n + 1); ha2.resize(n + 1);
    build();
  }

  void build(){
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i <= n; i++){
      pw1[i] = pw1[i - 1] * base % M1;
      pw2[i] = pw2[i - 1] * base % M2;
      
      ha1[i] = (ha1[i - 1] * base + v[i]) % M1;
      ha2[i] = (ha2[i - 1] * base + v[i]) % M2;
    }
  }

  pair<int, int> get(int l, int r){        // 1 - indexed
    int h1 = (ha1[r] - (ha1[l - 1] * pw1[r - l + 1] % M1) + M1) % M1;
    int h2 = (ha2[r] - (ha2[l - 1] * pw2[r - l + 1] % M2) + M2) % M2;

    return {h1, h2};
  }
};


signed main(){

    fast_cin();
      
       int n;
      cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];   // 1 - indexed
      
    HashV h(a);
  
   cout<<h.get(1, 5)<<endl;      // hash [l, r]
        
    return 0;
}

