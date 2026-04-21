#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

/*
Minimum number of deletions and insertions to transform one string into another
Given two strings ‘str1’ and ‘str2’ of size m and n respectively.
 The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2.
 It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
Example:
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
Minimum Insertion = 0 
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

   // x ke LCS e convert korte koyta remove kora lagse
   // LCS ke y te convert korte koyta add kora lagse
   // ei 2 tar sum hocche total operation

   cout<<"Minimum Deletion "<<n-dp[n][m]<<endl;
   cout<<"Minimum Insertion" << m-dp[n][m]<<endl;
    


    return 0;
}