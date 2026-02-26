#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
 int n, m, k;
 
vector<pair<int,int>> g[N];

void dijkstra_k_shortest(int source) {
      const long long inf = 1e18;
    vector<vector<long long>> dist(n + 1, vector<long long>(k, inf));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[source][0] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        pair<long long,int> top = pq.top();
        long long d = top.first;
        int u = top.second;
        pq.pop();

        if (dist[u][k - 1] < d) continue;

        for (auto i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int wt = g[u][i].second;
            long long newDist = d + wt;
            if (newDist < dist[v][k - 1]) {
                dist[v][k - 1] = newDist;
                sort(dist[v].begin(), dist[v].end());
                pq.push({newDist, v});
            }
        }
    }
    // Print 1st to k-th smallest distances to node n
    for (int i = 0; i < k; i++) {
        if (dist[n][i] == inf) cout << -1 << " ";
        else cout << dist[n][i] << " ";
    }
    cout << "\n";
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

     cin>>n>>m>>k;
      for(int i = 0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({v, w});
      }      
        dijkstra_k_shortest(1); 
       
  return 0;
}
