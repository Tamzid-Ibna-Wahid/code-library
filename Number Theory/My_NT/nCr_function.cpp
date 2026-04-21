#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
 // binomial coefficient O(r)  it is work for small n and r (20 - 30)
int nCr(int n, int r) {
    int sum = 1;
    for (int i = 1; i <= r; i++) {
        sum = sum * (n - r + i);
        sum /= i;
    }
    return sum;
}


// this is good one
vector<int>fact(N);

void factorial(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i] = mod_mul(fact[i-1], i);
    }
}

int nCr(int n, int r) {
   if(n<r)return 0;
    return mod_mul(inv(fact[n-r]), mod_mul(fact[n],inv(fact[r])));
}
int nPr(int n, int r){
    return mod_mul(fact[n], inv(fact[n - r]));
}

int main(){


    
    return 0;
}