#include <bits/stdc++.h>
using namespace std;

struct Block {
    int x, y, h;
};

vector<Block> blocks;
int dp[200];

int solve(int i) {
    if (dp[i] != -1) return dp[i];
    int best = 0;
    for (int j = 0; j < blocks.size(); j++) {
        if (blocks[j].x < blocks[i].x && blocks[j].y < blocks[i].y) {
            best = max(best, solve(j));
        }
    }
    return dp[i] = best + blocks[i].h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tc = 1;
    while (cin >> n && n) {
        blocks.clear();

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;

            // 3 orientations
            blocks.push_back({max(x,y), min(x,y), z});
            blocks.push_back({max(y,z), min(y,z), x});
            blocks.push_back({max(x,z), min(x,z), y});
        }

        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (int i = 0; i < blocks.size(); i++) {
            ans = max(ans, solve(i));
        }

        cout << "Case " << tc++ << ": maximum height = " << ans << "\n";
    }
    return 0;
}
