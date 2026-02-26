#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


const int N = 3e5 + 9;  // copy this one also
const int inf = 2e9;    // copy this one also
struct st {
  int a, b, cost;
}e[N];
signed main(){
  fast_cin();   
  // Taking the input
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) cin >> e[i].a >> e[i].b >> e[i].cost;      
  int s;
  cin >> s; //is there any negative cycle which is reachable from s?  
/*
d[i] = inf → only checks for cycles reachable from s.
d[i] = 0 → checks for cycles anywhere in the graph (disconnected parts included).
*/   
  vector<int> d (n+1, inf); //for finding any cycle(not necessarily from s) set d[i] = 0 for all i
  d[s] = 0;
  vector<int> p (n+1, -1);
  int x;  // if x is not -1 in nth iteration it means there is a negative cycle
  for (int i=0; i<n; ++i) {
    x = -1;
    for (int j=0; j<m; ++j) {
      if (d[e[j].a] < inf) {
        if (d[e[j].b] > d[e[j].a] + e[j].cost) {
          d[e[j].b] = max (-inf, d[e[j].a] + e[j].cost);  //for overflow
          p[e[j].b] = e[j].a;
          x = e[j].b;
        }
      }
    }
  }
  
  if (x == -1) cout << "No negative cycle from "<<s;
  else {
    int y = x; //x can be on any cycle or reachable from some cycle
    
    for (int i=0; i<n; ++i) y = p[y];

    vector<int> path;
    for (int cur=y; ; cur=p[cur]) {
      path.push_back (cur);
      if (cur == y && path.size() > 1) break;
    }
    reverse (path.begin(), path.end());

    cout << "Negative cycle: ";
    for (int i=0; i<path.size(); ++i) cout << path[i] << ' ';
        
  }
  // x only tell about is there has any negative cycle in the graph or not
  // if we want to know which node will be -inf for negative cycle we have to run bellman ford again and if the node distance is changing then we put  d[e[j].b] = -INF
  // https://cses.fi/problemset/result/14089227/     
    return 0;
}