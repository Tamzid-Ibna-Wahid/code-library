#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

/*
A string s is beautiful if it can be expressed in the form:
s= t + t′+ t
You are given a string s. Find the number of beautiful substrings of s

*/


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
};


struct Manacher {
  vector<int> p[2];
  // p[1][i] = (max odd length palindrome centered at i) / 2 [floor division]
  // p[0][i] = same for even, it considers the right center
  // e.g. for s = "abbabba", p[1][3] = 3, p[0][2] = 2
  Manacher(string s) {
    int n = s.size();
    p[0].resize(n + 1);
    p[1].resize(n);
    for (int z = 0; z < 2; z++) {
      for (int i = 0, l = 0, r = 0; i < n; i++) {
        int t = r - i + !z;
        if (i < r) p[z][i] = min(t, p[z][l + t]);
        int L = i - p[z][i], R = i + p[z][i] - !z;
        while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) 
          p[z][i]++, L--, R++;
        if (R > r) l = L, r = R;
      }
    }
  }
  bool is_palindrome(int l, int r) {
    int mid = (l + r + 1) / 2, len = r - l + 1;
    return 2 * p[len % 2][mid] + len % 2 >= len;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   
   int t;
   cin>>t;
   while(t--){
         int n;
      cin>>n;
      string s; cin >> s;
      
      long long ans = 0;
      
      // all same check?
       int ok = true;
      for(int i = 1;i<n;i++){
        if(s[i-1]!=s[i]){
            ok = false; break;
        }
      }
      if(ok){
          for(int i = 1;i<=n;i++){
            if(i%3==0) ans += (n-i+1);
          }
          cout<<ans<<endl;
          continue;
      }      
      
      // if not same
      Manacher M(s);
      Hash H(s);
      
      for(int i = 0;i<n-1;i++){
        for(int j = 1 ; j<=M.p[0][i+1];j++){
            int start = i - j + 1;
            if(start+3*j>n)break;
            if(H.range(start, start+j) == H.range(start+ 2*j, start+3*j)){
                ans++;
            }
            
        }
      }
      cout<<ans<<endl;
   }
  return 0;
}

// https://codeforces.com/problemset/gymProblem/105883/A?adcd1e=caf4fysgo7bd6p&csrf_token=4f8f9397178d9fd8758eeb0a5e86d19e&__cf_chl_tk=3x5km9F5RgrdCQJvs01HcNxACGLugO9gV4dXshID3BM-1778302036-1.0.1.1-GM9Y_.ofbkMLsVNjUrJ0q5d0nq_vKN.8vh8XvNz.tN8
