#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 /*
 Longest Repeating Subsequence
Given a string, print the longest repeating subsequence 
such that the two subsequence don’t have same string character at same position,
 i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
Example:
Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' 
(second). Note that 'b' cannot be considered 
as part of subsequence as it would be at same
index in both.
 */




int main(){
     string s;
     cin>>s;
     string x = s;
     string y = s;
    int n = x.size();
    int m = y.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));   //dp[i][j] = for x length i and y length j longest common subsequence

    //base condition = if(i==0 || j==0)dp[i][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1] && i != j)dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }   
    cout<<dp[n][m]<<endl;
    
    return 0;





    
}