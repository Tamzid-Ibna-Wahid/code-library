#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

struct BIT {
    long long M[N], A[N];
    BIT() {
        memset(M, 0, sizeof M);
        memset(A, 0, sizeof A);
    }
    void update(int i, long long mul, long long add) {   // internal update function
        while (i < N) {
            M[i] += mul;
            A[i] += add;
            i |= (i + 1);
        }
    }
    void upd(int l, int r, long long x) {   // add x to range [l..r]
        update(l, x, -x * (l - 1));
        update(r, -x, x * r);
    }
    long long query(int i) {          // prefix sum query [1..i]
        long long mul = 0, add = 0;
        int st = i;
        while (i >= 0) {
            mul += M[i];
            add += A[i];
            i = (i & (i + 1)) - 1;
        }
        return mul * st + add;
    }
    long long query(int l, int r) {     // range sum query [l..r]
        return query(r) - query(l - 1);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;  // number of elements, number of queries

    vector<long long> a(n + 1); // 1-indexed input
    for (int i = 1; i <= n; i++) cin >> a[i];

    BIT t;

    // build the initial array
    for (int i = 1; i <= n; i++) {
        t.upd(i, i, a[i]);  // add a[i] to single element i
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // range update
            int l, r;
            long long x;
            cin >> l >> r >> x;
            t.upd(l, r, x);
        } else if (type == 2) { // range query
            int l, r;
            cin >> l >> r;
            cout << t.query(l, r) << "\n";
        }
    }

    return 0;
}
