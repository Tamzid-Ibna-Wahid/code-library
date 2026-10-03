#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


long long modExp(long long a, long long n, long long M) {
    long long res = 1;
     a %= M;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        n >>= 1;
    }
    return res;
}

// calculate a^n
long long binExp(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

void findFirstAndLastM(long long n, long long k, long long m)
{
    // Calculate Last m digits
    string lastM = to_string(modExp(n, k, binExp(10, m)));
    while(lastM.size() < m) lastM = '0' + lastM;

    // Calculate First M digits
    long double x = (long double)k * log10(n * 1.0);
    x -= (long long) x;
    long long firstM = (long long) pow(10.0, x + m - 1);

    // Print the result
    cout << firstM << " " << lastM << endl;
}



signed main(){

    fast_cin();
    
    int t; cin>>t;
    
   for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        int n, k;
        cin>>n>>k;
        findFirstAndLastM(n, k, 3);         
    }
        
        
        
    return 0;
}