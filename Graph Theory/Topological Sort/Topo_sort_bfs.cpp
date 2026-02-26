#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 5e5 + 10;

vector<int>g[N];
int vis[N];
void toposort(int source, vector<int>&indegree, vector<int>&topo){
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int current_vertex = q.front();
        q.pop();
        topo.push_back(current_vertex);
        for(auto &child : g[current_vertex]){
            indegree[child]--;
            if(indegree[child]==0){
                q.push(child);
                vis[child]=1;               
            }
        }
    }
}

signed main(){

    fast_cin();
        
  int n, m;
  cin>>n>>m;

  vector<int>indegree(n+1);
    
  for(int i = 0;i<m;i++){
      int u, v;
      cin>>u>>v;
      g[u].push_back(v);
      indegree[v]++;
  }
  vector<int>topo;
  
  for(int i = 1;i<=n;i++){
      if(indegree[i] == 0 && vis[i] == 0)toposort(i, indegree, topo);
  }
  
 for(auto &it:topo){
  cout<<it<<" ";
 }      
  
        
    return 0;
}