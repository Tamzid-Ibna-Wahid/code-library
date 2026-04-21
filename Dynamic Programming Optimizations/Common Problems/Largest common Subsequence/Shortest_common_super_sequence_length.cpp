#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

/*
Shortest Common SuperSequence length
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
Examples:

Input:   str1 = "geek",  str2 = "eke"
Output: "geeke"
*/



int main(){
    string x,y;
    cin>>x>>y;
    int n = x.size();
    int m = y.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));     //dp[i][j] = for String x of length i and string y of length j longest common subsequence length

    //base condition = if(i==0 || j==0)dp[i][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    // size(s1) + size(s2) - LCS

    cout<< n + m - dp[n][m];
    


    return 0;
}