#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
 const int N = 1e7+10;

bool arr[N]={false};

void sieve(){
     arr[0]=arr[1]=true;
     for(int i=2;i*i < N;i++){      
          if(!arr[i]){ 
               for(int j=i*i;j< N;j+=i){     
                arr[j]=true;                  //false=prime  true=composite
               } 
          }
     }
}



// More optimized

vector<int>prime;
const int N = 1e7+10;
bool arr[N]={false};
void sieve(){
     for(int i=3;i*i<N;i+=2){
          if(!arr[i]){
               for(int j=i*i;j<N;j+=i+i) arr[j]=true;     //false=prime  true=composite
          }
     }
     prime.push_back(2);
      for(int i=3;i<N;i+=2){
        if(!arr[i])prime.emplace_back(i);
     }
}










int main(){

    sieve();
   
}

