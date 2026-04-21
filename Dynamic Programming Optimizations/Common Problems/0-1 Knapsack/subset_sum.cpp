//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
int main(){
    
    int n,sum;
    cin>>n>>sum;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

   bool dp[n+1][sum+1];  // dp[i][j]  for array size i does there a subset_sum j ?

   // base case
   for(int i=0;i<=n;i++){
    for(int j=0;j<=sum;j++){
        if(i==0 && j==0)dp[i][j] = true;
        else if(j==0)dp[i][j]=true;
        else if(i==0)dp[i][j] = false;
    }
   }     
   

   for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
        if(v[i-1] <= j){
            dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
        }
        else dp[i][j] = dp[i-1][j];
    }
   }
   cout<<dp[n][sum]<<endl;

    
    return 0;
}