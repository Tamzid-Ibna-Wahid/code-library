#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Finding Minimum Spanning Tree using Kruskal's Algorithm
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
        if(parent[node] == node)return node;
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
    void unionRank(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
        if(pu == pv) return;
        if(rank[pu] == rank[pv]){   
            parent[pu] = pv;
            rank[pu]++;
        }
        else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else{
            parent[pv] = pu;
        }
    }
};


signed main(){

    fast_cin();
        
        int n, m;
        cin>>n>>m;

        vector<pair<int,pair<int,int>>> edge;        
        REPn(i,m){
            int u, v, w;
            cin>>u>>v>>w;
            edge.pb({w, {u, v}});
        }
        sort(all(edge));
        dsu d(n);
        int sum = 0;
        
        for(auto &it : edge){
            int weight = it.fi;
            int u = it.se.fi;
            int v = it.se.se;
            if(d.findpar(u) != d.findpar(v)){
                sum += weight;
                d.unionSize(u, v);
            }
        }
        cout<<sum<<endl;
// Related Problem
// https://codeforces.com/problemset/problem/25/D

        
        
    return 0;
}