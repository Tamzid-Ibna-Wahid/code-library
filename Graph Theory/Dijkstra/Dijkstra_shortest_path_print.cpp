#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const long long inf = 1e18;

vector<pair<int,long long>> g[N];
vector<int> vis(N,0);
vector<long long> dist(N,inf);
vector<int> parent(N, -1);

void dijkstra(int source){
    set<pair<long long,int>> st;  //{wt,node}
    st.insert({0,source});
    dist[source] = 0;

    while(st.size() > 0){
        
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto child : g[v]){
            int child_v = child.first;
            long long wt = child.second;
            
            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                parent[child_v] = v;              // Update parent for shortest path
                st.insert({dist[child_v],child_v});
            }
        }
    }
}

vector<int> reconstruct_path(int target) {
    vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y;
        long long z;
        cin>>x>>y>>z;
        x--; y--;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    
    dijkstra(0);
    
    if(dist[n-1]==inf) cout<<-1;
    else{
        vector<int> path = reconstruct_path(n-1);
        for(auto &it : path) cout<<it+1<<" ";
    }

    return 0;
}

// https://codeforces.com/problemset/problem/20/C