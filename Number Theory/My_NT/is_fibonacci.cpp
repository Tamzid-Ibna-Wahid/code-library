#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return (root * root == n);
}
bool isFibonacci(int n) {
    if (n == 0)return true;
    int a = 0, b = 1, c = 1;
    while (c < n){
        a = b;
        b = c;
        c = a + b;
    }
    return (c == n || isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4));
}

signed main(){

    fast_cin();
        
    int n;
    cin>>n;
    
    if(isFibonacci(n))yes;
    else no;
        
        
        
    return 0;
}