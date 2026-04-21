#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
/**
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by
 deleting some (can be none) of the characters without disturbing the relative positions 
 of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
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
    if(dp[n][m]==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}