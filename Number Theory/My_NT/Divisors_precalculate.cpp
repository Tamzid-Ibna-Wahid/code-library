#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

 // divisors

   const int N = 1e6+10;    
    vector<int>divisor[N];  // i th vector i er shob divisor store korbe
    
void divisors_function(){
    for(int i=2;i < N;i++){               
        for(int j=i;j<N;j+=i){   
        divisor[j].push_back(i);
        } 
    }
}

int main(){
    
      divisors_function();
    for(int i =1;i<10;i++){
        for(auto div : divisor[i]){
            cout<<div<<" ";
        }
        cout<<endl;
     }
    }

     

