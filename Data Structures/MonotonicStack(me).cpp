#include <bits/stdc++.h>
using namespace std;

struct monotonicStack {    
    monotonicStack() { }
    // nearest min to the left
    vector<int> premin(const vector<int>& a) {
        int n = a.size();
        vector<int> premin(n);
        vector<pair<int, int>> pmn;
        pmn.push_back({INT_MIN, -1}); // Sentinel value smaller than any element
        for (int i = 0; i < n; i++) {
            while (pmn.back().first >= a[i]) pmn.pop_back();
            premin[i] = i - pmn.back().second;
            pmn.push_back({a[i], i});
        }
        return premin;
    }
    // nearest max to the left
    vector<int> premax(const vector<int>& a) {
        int n = a.size();
        vector<int> premax(n);
        vector<pair<int, int>> pmx;
        pmx.push_back({INT_MAX, -1}); // Sentinel value larger than any element

        for (int i = 0; i < n; i++) {
            while (pmx.back().first <= a[i]) pmx.pop_back();
            premax[i] = i - pmx.back().second;
            pmx.push_back({a[i], i});
        }
        return premax;
    }
    // nearest min to the right
    vector<int> sufmin(const vector<int>& a) {
        int n = a.size();
        vector<int> sufmin(n);
        vector<pair<int, int>> smn;
        smn.push_back({INT_MIN, n});

        for (int i = n - 1; i >= 0; i--) {
            while (smn.back().first > a[i]) smn.pop_back();
            sufmin[i] = smn.back().second - i;
            smn.push_back({a[i], i});
        }
        return sufmin;
    }
    // nearest max to the right
    vector<int> sufmax(const vector<int>& a) {
        int n = a.size();
        vector<int> sufmax(n);
        vector<pair<int, int>> smx;
        smx.push_back({INT_MAX, n});

        for (int i = n - 1; i >= 0; i--) {
            while (smx.back().first < a[i]) smx.pop_back();
            sufmax[i] = smx.back().second - i;
            smx.push_back({a[i], i});
        }
        return sufmax;
    }
};
void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;    
    monotonicStack ms;
    vector<int> premin = ms.premin(a),
                premax = ms.premax(a),
                sufmin = ms.sufmin(a),
                sufmax = ms.sufmax(a); 
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * premax[i] * sufmax[i] * a[i];
        ans -= 1LL * premin[i] * sufmin[i] * a[i];
    }
    cout << ans << "\n";
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}

// https://codeforces.com/problemset/problem/817/D