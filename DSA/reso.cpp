#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300005;

vector<int> tree[MAXN];
int depth[MAXN];
ll result;

void dfs(int u, int parent, map<int, int>& counts) {
    vector<map<int, int>> child_counts;
    for (int v : tree[u]) {
        if (v == parent) continue;
        map<int, int> counts_v;
        depth[v] = depth[u] + 1;
        dfs(v, u, counts_v);
        child_counts.push_back(move(counts_v));
    }

    if (child_counts.empty()) {
        // Leaf node
        counts[1] = 1;
    } else {
        // Find the largest map
        int idx_big = -1, max_size = -1;
        for (int i = 0; i < child_counts.size(); ++i) {
            if (child_counts[i].size() > max_size) {
                max_size = child_counts[i].size();
                idx_big = i;
            }
        }
        counts = move(child_counts[idx_big]);

        for (int i = 0; i < child_counts.size(); ++i) {
            if (i == idx_big) continue;
            auto& counts_small = child_counts[i];
            // Compute contributions
            for (auto& p_small : counts_small) {
                int s_small = p_small.first;
                int cnt_small = p_small.second;
                for (auto& p_big : counts) {
                    int s_big = p_big.first;
                    int cnt_big = p_big.second;
                    int min_s = min(s_small, s_big);
                    ll contrib = (2LL * min_s - 1) * cnt_small * cnt_big;
                    result += contrib;
                }
            }
            // Merge counts_small into counts
            for (auto& p : counts_small) {
                counts[p.first] += p.second;
            }
        }
        // Add current node
        counts[1] += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // Reset data structures
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
        }
        result = 0;

        // Read tree edges
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            // Build tree
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        map<int, int> counts;
        depth[1] = 0;
        dfs(1, 0, counts);

        cout << result << '\n';
    }
    return 0;
}