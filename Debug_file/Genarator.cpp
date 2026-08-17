#include<bits/stdc++.h>
using namespace std;

#define ll long long
 
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}
 
 
// Random Real Number Generator:
/*
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
inline double gen_random(double l, double r) {
    return uniform_real_distribution<double>(l, r)(rng);
}
*/


void  Random_array(){
      int n = gen_random(1,10);
       cout<<n<<endl;
       for(int i=1;i<=n ; i++) cout<<gen_random(-10,10)<<" ";
}

void  Permutation(){
     int n = gen_random(1,10);
     vector<int> v;
    for(int i=1;i<=n;i++)v.push_back(i);
    shuffle(v.begin(),v.end(),rng);
    
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}

void String_gen(){
     int n = gen_random(1,10);
     for(int i=0;i<n;i++)cout<<'a' + gen_random(0,25);
}

void special_String(){
     int n = gen_random(1,10);
     vector<char> c = {'p','q','r','s'};
    for(int i=0;i<n;i++){
        cout<<c[gen_random(0,c.size()-1)];
    }
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    freopen("input.txt","w",stdout);
    
   int t = gen_random(1,10);
   
   cout<<t<<endl;
   
   while(t--){
      Random_array();
      
      cout<<endl;
   }
        
  

    return 0;
}