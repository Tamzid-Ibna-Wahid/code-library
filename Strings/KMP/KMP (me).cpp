#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const ll mod = 1e9 + 7;

// O(size of string)
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

signed main() {
    string t;  // The text in which to search
    cin >> t;

    string str;  // The pattern to find
    cin >> str;

    vector<int> pf = prefix_function(str);

    int pos = -1;
    int i = 0, j = 0;
    int count = 0;  // To count the number of matches
    while (i < t.size()) {
        if (t[i] == str[j]) {
            j++;
            i++;
        }
        else {
            if (j != 0) 
                j = pf[j - 1];  // Update j based on prefix function
            else 
                i++;  // Move forward in text
        }
        if (j == str.size()) {
            count++;
            pos = i - j;  // Found a match, update position
            // Uncomment the next line if you want to find all occurrences
            // cout << "Pattern found at index: " << pos << endl; 
            j = pf[j - 1];  // Continue to find other matches
        }
    }
    cout<<count<<endl;
    cout << pos << endl;

    return 0;
}
