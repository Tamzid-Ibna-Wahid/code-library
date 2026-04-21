#include<bits/stdc++.h>
using namespace std;

#define int long long

class dsu{
public:
    vector<int> parent, size, rank;
public:
    dsu(int n){
        for(int i = 0;i<=n;i++){
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }
    int findpar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }
    void unionSize(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){   // attach smaller to bigger
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


const int N = 3e5 + 9, LG = 18;
vector<pair<int,int>> g[N]; // {to, weight}

int par[N][LG + 1];
int mx[N][LG + 1]; // max edge weight to ancestor
int dep[N];

void dfs(int u, int p = 0, int w = 0) {
  par[u][0] = p;
  mx[u][0] = w;
  dep[u] = dep[p] + 1;

  for (int i = 1; i <= LG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
    mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
  }

  for (auto &[v, wt] : g[u]) {
    if (v == p) continue;
    dfs(v, u, wt);
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) {
    if (dep[par[u][k]] >= dep[v]) {
      u = par[u][k];
    }
  }
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) {
    if (par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }
  return par[u][0];
}

int max_edge_on_path(int u, int v) {
  int ans = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) {
    if (dep[par[u][k]] >= dep[v]) {
      ans = max(ans, mx[u][k]);
      u = par[u][k];
    }
  }
  if (u == v) return ans;

  for (int k = LG; k >= 0; k--) {
    if (par[u][k] != par[v][k]) {
      ans = max(ans, mx[u][k]);
      ans = max(ans, mx[v][k]);
      u = par[u][k];
      v = par[v][k];
    }
  }
  ans = max(ans, mx[u][0]);
  ans = max(ans, mx[v][0]);

  return ans;
}

// considaring graph is connected *****

int32_t main() {
    
  int n, m; cin >> n >> m;
  
  vector<tuple<int, int, int>> edge;
  set<tuple<int, int, int>> s;
  
  for (int i = 1; i <= m; i++) {
    int u, v, w; cin >> u >> v >> w;
    edge.push_back({u, v, w});
    s.insert({w, u, v});
  }
  
  dsu d(n);
  int mn_cost = 0;
  for(auto &[w, u, v] : s){
    if(d.findpar(u) == d.findpar(v))continue;
    mn_cost += w;
    d.unionSize(u, v);
    // make MST
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  dfs(1); 
  
 vector<long long> all;

  for(auto &[u, v, w] : edge){
      int candidate = mn_cost + w - max_edge_on_path(u, v);
      all.push_back(candidate);
  }

  sort(all.begin(), all.end());

    long long second_mst = -1;

    for(int i = 0; i < all.size(); i++){
        if(all[i] > mn_cost){
            second_mst = all[i];
            break;
        }
    }

  cout << second_mst << endl;
  
  return 0;
}

//https://vjudge.net/contest/745010#problem/B    //Note : graph is not connected