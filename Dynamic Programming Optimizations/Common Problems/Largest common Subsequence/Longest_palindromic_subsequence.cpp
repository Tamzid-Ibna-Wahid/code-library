#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
int main(){
    string s;
    cin>>s;

    string ans = LCS(s,reverse(s.begin(),s.end()));  // LCS = longest common subsequence

    cout<<ans<<endl;      // longest palindromic subsequence

    // minimum number of delatation in string to make palindrome
    //  min number of delation = string length - palindrome length

    // minimum number of addition to make string palindrome
    // minimum number of addition = minimum number of delation

    
    return 0;
}
