#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<long long>(x,y)(rnd)
typedef uint64_t ull;
struct H {
  ull x; H(ull _x=0) : x(_x) {}
  H operator+(H o) { return x + o.x + (x + o.x < x); }
  H operator-(H o) { return *this + ~o.x; }
  H operator*(H o) { auto m = (__uint128_t)x * o.x;
    return H((ull)m) + (ull)(m >> 64); }
  ull get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
  friend std::ostream& operator << (std::ostream &os, const H &h){ return os << h.x; }
  friend std::istream& operator >> (std::istream &is, H &h){int x; cin >> x; return h.x = x, is;}
};
static const H C = (long long)rng(1e10,1e12); // (order ~ 3e9; random also ok)

struct Hash {
  vector<H> ha, pw;
  Hash(string& str) : ha(str.size() +1), pw(ha) {
    pw[0] = 1;
    for (int i = 0; i < str.size(); i++)
      ha[i+1] = ha[i] * C + str[i],
      pw[i+1] = pw[i] * C;
  }
  H range(int a, int b) {          // hash [a, b)
    return ha[b] - ha[a] * pw[b - a];
  }
  void insert(char a){
    ha.push_back(ha.back()*C + a);
    pw.push_back(pw.back()*C);
  }
  /*
    bool isPalindrom(int l, int r){   // [l, r]
      int i = n - 1 - r;
      int j = n - 1 - l;
      return st.range(l, r + 1).x == rv.range(i, j + 1).x;
    }
  */
};


signed main(){

    fast_cin();
      
      string s, t;
      cin>>s>>t;
         
      int k; cin>>k;
         
      int n = s.size();
        
      vector< H > v;

      Hash h(s);
            
    for(int i = 0; i < n; i++){
    int x = 0;
    for(int j = i; j < n; j++){
      x += !(t[s[j] - 'a'] - '0');
      if(x > k)break;
      v.push_back(h.range(i, j + 1));
    }
  }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
 
    cout << v.size() << endl;
        
    return 0;
}

// https://codeforces.com/contest/271/problem/D