#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
int main(){
    int n;
    cin>>n;
      vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    int range = accumulate(v.begin(),v.end(),0ll);
    
      bool dp[n+1][range+1];  // dp[i][j]  for array size i does there a subset_sum j ?

   // base case
   for(int i=0;i<=n;i++){
    for(int j=0;j<=range;j++){
        if(i==0 && j==0)dp[i][j] = true;
        else if(j==0)dp[i][j]=true;
        else if(i==0)dp[i][j] = false;
    }
   }     

   for(int i=1;i<=n;i++){
    for(int j=1;j<=range;j++){
        if(v[i-1] <= j){
            dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
        }
        else dp[i][j] = dp[i-1][j];
    }
   }

   int mn_dif = INT_MAX;

   for(int j = 1 ; j<=(range/2);j++){
    if(dp[n][j])
    mn_dif = min(mn_dif , range - (2*j));
   }
   


    return 0;
}