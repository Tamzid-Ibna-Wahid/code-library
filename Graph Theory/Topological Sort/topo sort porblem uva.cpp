#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int tc = 1;

    while (cin >> n) {

        vector<string> beverage(n);
        map<string, int> mp;

        for (int i = 0; i < n; i++) {
            cin >> beverage[i];
            mp[beverage[i]] = i;
        }

        int m;
        cin >> m;

        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;

            int u = mp[a];
            int v = mp[b];

            g[u].push_back(v);
            indegree[v]++;
        }

        // Min-heap to maintain input order priority
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                pq.push(i);
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();

            ans.push_back(u);

            for (auto v : g[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    pq.push(v);
                }
            }
        }

        cout << "Case #" << tc++
             << ": Dilbert should drink beverages in this order:";

        for (auto x : ans) {
            cout << " " << beverage[x];
        }

        cout << ".\n\n";
    }

    return 0;
}

// https://vjudge.net/problem/UVA-11060