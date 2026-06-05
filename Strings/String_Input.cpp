#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


signed main(){
    fast_cin();
    
    string s;
    getline(cin, s);
    
    stringstream ss(s);
    string temp;
    
    std::vector<string> v;
    
    while(ss>>temp){
        v.push_back(temp);
    }
    
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
   
   // input : aa bbb f g
  /*  output :
      a
      bbb
      f
      g
  */
    
            string t = "abc";
         sort(t.begin(), t.end());
         
         do{
          cout<<t<<endl;
         }
         while(next_permutation(all(t)));
        
        
        
    return 0;
}