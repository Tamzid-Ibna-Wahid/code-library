#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

 
 
 
 
 
 
 
//sigma(n) = {p_1^{e_1 + 1} - 1}/{p_1 - 1} * {p_2^{e_2 + 1} - 1}/{p_2 - 1}....{p_k^{e_k + 1} - 1}/{p_k - 1}

long long SumOfDivisors(long long num) {
    long long total = 1;
    long long i = 2;

    for(int i = 2 ;i * i <= num; i++){
        if (num % i == 0) {
            int e = 0;

            while (num % i == 0) {
                num /= i;
                e++;
            }

            long long sum = 0;
            long long pow = 1;

            while (e >= 0) {
                sum += pow;
                pow *= i;
                e--;
            }

            total *= sum;
        }
    }

    if (num > 1) total *= (1 + num);

    return total;
}

// first calculate prime
long long SumOfDivisors(long long num) {
    long long total = 1;
    long long i = 2;

    for(int i = 0 ;prime[i] * prime[i] <= num; i++){
        int p = prime[i];
        
        if (num % p == 0) {
            int e = 0;

            while (num % p == 0) {
                num /= p;
                e++;
            }

            long long sum = 0;
            long long pow = 1;

            while (e >= 0) {
                sum += pow;
                pow *= p;
                e--;
            }

            total *= sum;
        }
    }

    if (num > 1) total *= (1 + num);

    return total;
}


signed main(){

    fast_cin();
    
        int n = 5;
        
        cout<<SumOfDivisors(n);
        
        
        
        
    return 0;
}