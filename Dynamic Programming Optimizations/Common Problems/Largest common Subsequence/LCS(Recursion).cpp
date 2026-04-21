#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

/*Longest Common Subsequence Problem solution using recursion
Given two sequences, find the length of longest common subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 

For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.
*/

vector<vector<int>>dp(1001,vector<int>(1001,-1));
 
int lcm(stirng s,string y,int n,int m){
    if(n==0 || m==0 )return 0;
    if(dp[n][m]!=-1)return dp[n][m];

    if(x[n-1]==y[m-1])return dp[n][m] = lcs(x,y,n-1,m-1)+1;
    else return dp[n][m] = max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
}


int main(){
    string x,y;
    cin>>x>>y;
    int ans = lcm(x,y,x.size(),y.size());

    cout<<ans<<endl;
    
    return 0;
}