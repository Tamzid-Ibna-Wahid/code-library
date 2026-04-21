#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;


// Min_number_of_way
 
int main(){
    int n,sum;
    cin>>n>>sum;
    
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    int dp[n+1][sum+1];   // dp[i][j] = for array size i , minium number of ways to create sum j

    // base case
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j==0)dp[i][j] =INT_MAX-1;
            else if(j==0)dp[i][j] = INT_MAX-1;
            else if(i==0)dp[i][j] = 0;
            else if(i==1 && j>0){
                if(j%v[0]==0)dp[i][j]=j/v[0];
                else dp[i][j] = INT_MAX-1;
            }
        }
    }


    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(v[i-1]<=j){
                dp[i][j] = min(dp[i-1][j] , dp[i][j-v[i-1]] + 1);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    cout<<dp[n][sum]<<endl;

    
    return 0;
}