#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int timer;
void dfs(int node, int parent, vector<int> g[], vector<int>& vis,
    vector<int>& tin, vector<int>& low, vector<pair<int,int>>& bridge){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
    for (auto &it : g[node]) {
        if (it == parent) continue;
        if (!vis[it]) {
            dfs(it, node, g, vis, tin, low, bridge);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node]) {
                bridge.push_back({node, it});  
            }
        } 
        else {
            low[node] = min(low[node], tin[it]);
        }
    }
}

signed main(){

    fast_cin();
    
   timer = 0;
   int n, m;
   cin>>n>>m;
   
   vector<int>g[n];
   
   for(int i = 0;i<m;i++){
    int u, v;
    cin>>u>>v; u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
   }
   vector<int>vis(n,0), tin(n), low(n);
   vector<pair<int,int>>bridge;
   
   for(int i = 0;i<n;i++){
    if(vis[i])continue;
    dfs(i, -1, g, vis, tin, low, bridge);
   } 
   
    cout<<bridge.size() <<" critical links"<<endl; 

     for(auto &it: bridge){
        cout<<it.first<<" - "<<it.second<<endl;
    }
    
// https://lightoj.com/problem/critical-links      
        
    return 0;
}