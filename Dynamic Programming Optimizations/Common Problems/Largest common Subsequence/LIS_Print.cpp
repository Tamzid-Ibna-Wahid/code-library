#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;


vector<int> lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1), p(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}

string lis(const string& s) {
    int n = s.size();
    vector<int> d(n, 1), p(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] < s[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    string subseq;
    while (pos != -1) {
        subseq.push_back(s[pos]);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}


int main(){
    
    int n;
    cin>>n;
    
    vector<int>v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
        
    vector<int> ans = lis(v);

    
    return 0;
}