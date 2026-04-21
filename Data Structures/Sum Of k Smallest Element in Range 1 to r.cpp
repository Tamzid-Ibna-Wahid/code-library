#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int &x : v) cin >> x;

    vector<int> comp = v;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    auto getId = [&](int x) {
        return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
    };

    int M = comp.size();

    vector<ll> bitCnt(M + 1, 0), bitSum(M + 1, 0);

    auto update = [&](int val) {
        int id = getId(val);
        for (; id <= M; id += id & -id) {
            bitCnt[id] += 1;
            bitSum[id] += val;
        }
    };

    auto getKSum = [&](int k) {
        int pos = 0;
        ll cnt = 0, sum = 0;

        for (int pw = 1 << 20; pw; pw >>= 1) {
            if (pos + pw <= M && cnt + bitCnt[pos + pw] <= k) {
                cnt += bitCnt[pos + pw];
                sum += bitSum[pos + pw];
                pos += pw;
            }
        }

        if (pos < M && cnt < k) {
            int val = comp[pos];
            sum += 1LL * (k - cnt) * val;
        }

        return sum;
    };

    vector<array<int,3>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    }

    // sort by x
    sort(queries.begin(), queries.end());

    vector<int> ans(q);

    int ptr = 0;

    for (auto &[x, y, idx] : queries) {
        // insert up to x
        while (ptr < x) {
            update(v[ptr]);
            ptr++;
        }

        // binary search answer
        int l = 1, r = x, res = 0;

        while (l <= r) {
            int mid = (l + r) / 2;    // number of element
            if (getKSum(mid) <= y) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ans[idx] = res;
    }

    for (int x : ans) cout << x << '\n';
}


// https://www.codechef.com/problems/MXSZ