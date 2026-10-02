#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

string multi(string a, string b) {
    if (a == "0" || b == "0") return "0";
    if (a == "1") return b;
    if (b == "1") return a;

    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + j] += (a[i] - '0') * (b[j] - '0');
            if (res[i + j] >= 10) {
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();

    string c = "";
    for (int i = res.size() - 1; i >= 0; i--) c.push_back(res[i] + '0');

    return c;
}

signed main(){

    fast_cin();
        
    return 0;
}