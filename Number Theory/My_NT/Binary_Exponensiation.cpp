#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int binExp(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
} 

int main(){
    cout<<binExp(2,3);
    
    return 0;
}