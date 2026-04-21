#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

string multyply(string a, int b){
  int carry = 0;
 string ans = "";
  for(int i = 0; i < a.size(); i++){
    carry = ((a[i] - '0') * b + carry);
    ans += carry % 10 + '0';
    carry /= 10;
  }
  while(carry != 0){
    ans += carry % 10  + '0';
    carry /= 10;
  }
  return ans;
}



signed main(){

    fast_cin();
        
    int n;
    cin>>n;
    
    string ans = "1";
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ans = multyply(ans, x);
    } 
    reverse(all(ans));
    
    cout<<ans<<endl; 
        
        
        
    return 0;
}