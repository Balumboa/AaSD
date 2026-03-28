#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        graph[v].push_back(w);
    }
    vector<int> permutation(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        permutation[x] = i;
    }
    bool ans = true;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < (int)graph[i].size(); j++) {
            int v = i;
            int w = graph[i][j];
            if (permutation[v] > permutation[w]) {
                ans = false;
            }
        }
    }
    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
