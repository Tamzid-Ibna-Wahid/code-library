#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int M = 1000000007;
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y)            uniform_int_distribution<int>(x,y)(rng)

struct mint{
    int32_t x;
    inline mint(int x = 0) : x(x % M){};
    inline mint & operator = (int n){return x = n, *this;}
    inline mint & operator += (mint a){return (x += a.x) >= M && (x -= M), *this;}
    inline mint & operator -= (mint a){return (x -= a.x) < 0 && (x += M), *this;}
    inline mint & operator *= (mint a){return x = (uint64_t) x * a.x % M, *this;}
    inline mint & operator %= (mint a){return (x %= a.x), *this;}
    inline mint & operator ++(int32_t){return (*this += 1), *this;}
    inline mint & operator --(int32_t){return (*this -= 1), *this;}
    inline mint & operator ++(){return (*this += 1), *this;}
    inline mint & operator --(){return (*this -= 1), *this;}
    inline mint & operator ^= (int p){
        mint ans = 1, w = *this;
        for(; p; p >>= 1, w *= w)if(p & 1)ans *= w;
        return x = ans.x, *this;
    };

    inline mint & operator /= (mint a){return *this *= (a ^= (M - 2)); }
    friend inline mint operator + (mint a, mint b){return a += b;}
    friend inline mint operator - (mint a, mint b){return a -= b;}
    friend inline mint operator * (mint a, mint b){return a *= b;}
    friend inline mint operator / (mint a, mint b){return a /= b;}
    friend inline mint operator % (mint a, mint b){return a %= b;}
    friend inline mint operator ^ (mint a, mint b){return a ^= b.x;}
    friend inline mint operator ^ (mint a, int b){return a ^= b;}
    friend inline mint operator & (mint a, mint b){return a.x & b.x;}
    friend inline mint operator | (mint a, mint b){return a.x | b.x;}

    friend inline bool operator < (const mint &a, const mint &b){return a.x < b.x;}
    friend inline bool operator > (const mint &a, const mint &b){return a.x > b.x;}
    friend inline bool operator <= (const mint &a, const mint &b){return a.x <= b.x;}
    friend inline bool operator >= (const mint &a, const mint &b){return a.x >= b.x;}
    friend inline bool operator == (const mint &a, const mint &b){return a.x == b.x;}
    friend inline bool operator != (const mint &a, const mint &b){return a.x != b.x;}
    explicit operator bool() const { return x != 0; }


    friend std::ostream& operator<<(std::ostream& os, mint const& a) {return os << a.x;}
    friend std::istream& operator>>(std::istream &is, mint& a){
        int y; is >> y; (y %= M) < 0 && (y += M); 
        return a.x = y, is;        
    }
};
#define H mint
const H C = rng(8.8e8, 1e9);

struct HashST{
  int n; string str;
  vector<H> t, pw;
  HashST(string s){ 
    str = "#" + s;          // 1-indexed
    n = str.size() - 1;
    pw.resize(n + 2); t.resize(2 * n + 2);
    build();
  }

  void build(){
    pw[0] = pw[1] = 1;
    for(int i = 1; i <= n; i++){
      t[i + n] = pw[i] * str[i];
      pw[i + 1] = pw[i] * C;
    }
    for(int i = n; i >= 1; i--){
      t[i] = t[i << 1] + t[i << 1 | 1];
    }
  }
  void update(int i, char c){     // 1-indexed
    i += n;
    t[i] = pw[i - n] * c;
    for(i >>= 1; i; i >>= 1){
      t[i] = t[i << 1] + t[i << 1 | 1];
    }
  }

  H query(int l, int r){   // [l, r]
    H div = pw[l];
    l += n; r += n;
    H ans = 0;
    for(; l <= r; l >>= 1, r >>= 1){
      if(l % 2 == 1)ans = ans + t[l++];
      if(r % 2 == 0)ans = ans + t[r--];
    }
    return ans / div;
  }
};

signed main(){

    fast_cin();
    
    string s;
    cin >> s;

    HashST hs(s);

    // check substring equality
    int l1=1, r1=3;
    int l2=4, r2=6;

    if(hs.query(l1,r1) == hs.query(l2,r2))
        cout<<"Equal\n";
    else
        cout<<"Not Equal\n";

    // update example
    hs.update(2,'z');
        
        
        
        
    return 0;
}