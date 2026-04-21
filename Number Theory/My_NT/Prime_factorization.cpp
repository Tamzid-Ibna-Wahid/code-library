#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
 const int N = 1e7+10;
vector<int>lp(N,0),hp(N,0);   // 10 => 2(lowest prime) * 5(higest prime)

bool arr[N]={false};
void sieve(){
     arr[0]=arr[1]=true;
     for(int i=2; i < N;i++){      
          if(!arr[i]){ 
            lp[i]=hp[i]=i;
               for(int j=2*i; j < N;j+=i){     
                arr[j]=true;                  //false=prime  true=composite
                hp[j]=i;
                if(lp[j]==0){
                    lp[j]=i;
                }
               } 
          }
     }
}

// for a single element
void prime_factorization(int n){
   for(int i = 2; i*i<=n;i++){
      if(n%i==0){
         int cnt = 0;
         while(n%i==0){
            cnt++;
            n /= i;
         }
         cout<<i<<"^"<<cnt<<endl;
      }
   }
      if(n>1)cout<<n<<" "<<1<<endl;
}


int main(){

    sieve();
    int num;
    cin>>num;

    vector<int>prime_factors;

    while(num>1){
        int prime_factor = hp[num];  // we can use lp
        while(num% prime_factor==0){
            num /=prime_factor;
            prime_factors.push_back(prime_factor);
        }
    }
    
// print
for(int factor : prime_factors)cout<<factor<<" ";
    
}




//count er maddhome korte chaile
    num = 1356;
   map<int,int>mp;
    while(num>1){
        int prime_factor = hp[num];  // we can use lp
        while(num% prime_factor==0){
            num /=prime_factor;
           mp[prime_factor]++;
        }

    }
// print
for(auto it : mp)cout<<"Prime "<<it.first<<" count "<<it.second<<endl;
    

 