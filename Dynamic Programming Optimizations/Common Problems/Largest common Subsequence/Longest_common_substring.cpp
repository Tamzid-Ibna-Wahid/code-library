#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

/*Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
Examples:
Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
The longest common substring is “Geeks” and is of length 5.
*/


int main(){
    string x,y;
    cin>>x>>y;
    int n = x.size();
    int m = y.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));   //dp[i][j] = for x length i and y length j longest common substring

    //base condition = if(i==0 || j==0)dp[i][j]=0;

    int res = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                res = max(dp[i][j],res);
            }
            else dp[i][j] = 0 ;
        }
    }   
    cout<<res<<endl;
    
    return 0;
}