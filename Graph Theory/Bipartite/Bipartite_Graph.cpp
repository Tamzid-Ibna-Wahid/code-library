#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 5e5 + 10;

vector<int>g[N];
bool vis[N];
vector<int>colour(N,0);

bool is_bipartite = true;

void dfs(int vertex, int col){   // col = 1 or 2;
  
    colour[vertex] = col;
    vis[vertex] = true;

    for(int &child : g[vertex]){
     
         if(vis[child]){
            if(colour[child] == col){
                 is_bipartite = false;
                  return;
            }
           continue;
         }
         dfs(child, (col==1)?2 : 1);
         if(!is_bipartite) return;
    }
  
}

/*

A bipartite graph is a graph whose vertices can be divided into two disjoint sets, 
such that every edge connects a vertex from one set to a vertex in the other set. 

In simpler terms, it's a graph where you can color the nodes with two colors in a
way that no two adjacent nodes share the same color. 

 A graph will never be Bipartite if there is a odd length cycle in graph.
 so in question if there ask for finding is there exist odd length cycle or not 
 then we can just check is the graph Bipartite or not.

tree is always Bipartite.

*/


/*
Some common result:
1. An undirected graph where 
each node has at degree at least 2 will containa a cycle

2. A directed graph where each node has at
least 1 in-degree and at least 1 out-degree will contain
a cycle.

3. The sum of all degrees is even. the number of
vertices with odd degree is even

*/


signed main(){

    fast_cin();
        
    return 0;
}