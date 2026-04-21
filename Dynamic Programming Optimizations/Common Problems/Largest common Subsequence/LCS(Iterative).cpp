#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

/*Longest Common Subsequence Problem solution using recursion
Given two sequences, find the length of longest common subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 

For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.
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
    cout<<dp[n][m]<<endl;
    
    return 0;
}