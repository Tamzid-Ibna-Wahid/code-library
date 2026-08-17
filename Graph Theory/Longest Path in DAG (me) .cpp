#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


const int N = 5e5 + 10;
// find longest path in a DAG
vector<vector<int>>g(N);
bool vis[N];
vector<int>best(N, 0);
int longest = 0;
void dfs(int vertex){
    vis[vertex] = true;
    int mx = 0;
    for(auto &child : g[vertex]){
         if(!vis[child])dfs(child);
        best[vertex] = max(best[vertex], best[child] + 1);
    }
    best[vertex] = max(best[vertex], 1ll);
    longest = max(longest, best[vertex]);
}



signed main(){

    fast_cin();
      
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v); 
    }
    
    for(int i = 0;i<n;i++){
        if(!vis[i])dfs(i);
    }
    
      cout<<longest<<endl;
        
    return 0;
}