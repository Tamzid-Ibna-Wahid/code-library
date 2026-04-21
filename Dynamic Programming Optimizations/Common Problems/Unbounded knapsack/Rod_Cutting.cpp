#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

// max profit
 
int main(){
        int n, full_length;
        cin>>n>>full_length;
        vector<int>length(n),price(n);

         for(int i=0;i<n;i++)cin>>length[i];
        for(int i=0;i<n;i++)cin>>price[i];

    // dp[i][j] = for i size length array max price we can achieve

        vector<vector<int>>dp(n+1,vector<int>(full_length+1,0));     

   for(int i=1;i<=n;i++){
    for(int j=1;j<=full_length;j++){
        if(length[i-1] <= j){
            dp[i][j] =max (price[i-1] + dp[i][j-length[i-1]] , dp[i-1][j]);
        }
        else dp[i][j] = dp[i-1][j];
    }
   }

   cout<<dp[n][full_length]<<endl;
   


    return 0;
}