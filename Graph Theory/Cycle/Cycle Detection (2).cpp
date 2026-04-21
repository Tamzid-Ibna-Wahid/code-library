#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 5e5 + 10;

vector<int>g[N];
bool is_cycle = false;
vector<int> state(N, 0);  // 1 - > not visited   2 -> processing    3-> process done
vector<int>parent(N);

void reconstract_path(int cycle_start, int cycle_end){
  vector<int> cycle;
  cycle.push_back(cycle_start);
  for (int v = cycle_end; v != cycle_start; v = parent[v]) cycle.push_back(v);
  cycle.push_back(cycle_start);

  cout <<cycle.size()<<endl;
  reverse(cycle.begin(), cycle.end());
  for (int v : cycle) cout << v << " ";   
}

void find_cycle(int vertex){ 
     state[vertex] = 2;
    for(auto &child : g[vertex]){
     
    if(state[child] == 2){
        is_cycle = true;
        reconstract_path(child, vertex);
        return;
    }
    else if(state[child] == 3)continue;
    parent[child] = vertex;
    find_cycle(child);
    if(is_cycle)return;
    }
     state[vertex] = 3;
}

signed main(){

    fast_cin();
        
  int n, m;
  cin>>n>>m;
       
  for(int i = 0;i<m;i++){
    int u, v;
    cin>>u>>v;
    g[u].push_back(v);
  }
         
  for(int i = 1;i<=n;i++){
    if(state[i]>0)continue;
       find_cycle(i);
     if(is_cycle)break;
   }
       
   if(!is_cycle){
    cout<<"IMPOSSIBLE";
   }    
    
        
        
    return 0;
}