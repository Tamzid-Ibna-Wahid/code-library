#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"

#define REPn(i,n) for(ll i = 0; i < n; i++)
#define REPsn(i,s,n) for(ll i = s; i <= n; i++)

#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define INF 2e18
const ll mod = 1e9+7;
const int N = 2e5+10;


int cnt[N];

int num;
int n , k;

void add (int x){
    cnt[x]++;
    if(cnt[x]==1)num++;
}
void remove (int x){
    cnt[x]--;
    if(cnt[x]==0)num--;
}

bool isGood(){
    return num<=k;
}



signed main(){

     fast_cin();

      cin>>n>>k;

      std::vector<int> v(n);

      REPn(i,n)cin>>v[i];

      int l = 0;
     int res = 0;
          for(int r = 0 ; r<n;r++){
          add(v[r]);
          while(!isGood()){
          remove(v[l]);
          l++;
          }
      res += (r-l+1);
      }
      cout<<res;




    return 0;
}


// https://mirror.codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E