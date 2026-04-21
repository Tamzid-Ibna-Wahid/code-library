#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const long M = 1000000007; // modulo
map<long, long> F;

// 1 1 2 3 5 ........
// sum_0th_to_nth = f(n+2)-1        ex: (n=0 s=1) (n=1 s=2) (n=2 s=4)
int f(int n) {
    if (F.count(n)) return F[n];
    int k=n/2;
    if (n%2==0)return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;  // n=2*k
    else return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;  // n=2*k+1
}


signed main(){

    fast_cin();
        
    int n;
    F[0]=F[1]=1;         // note : use this line
    while (cin >> n)
    cout << (n==0 ? 0 : f(n-1)) << endl;
        
        
        
    return 0;
}