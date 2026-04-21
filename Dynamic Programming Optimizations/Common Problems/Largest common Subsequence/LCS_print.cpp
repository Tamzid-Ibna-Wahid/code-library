#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

/*
Printing Longest Common Subsequence
Given two sequences, print the longest subsequence present in both of them.
Example:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
*/


int main(){
    string x,y;
    cin>>x>>y;
    int n = x.size();
    int m = y.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));   //dp[i][j] = for x length i and y length j longest common subsequence

    //base condition = if(i==0 || j==0)dp[i][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }   
    // cout<<dp[n][m]; // max length of the subsequence

    int i = n,j = m;
    string ans;

    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

    
    return 0;
}