#include <bits/stdc++.h>

using namespace std;

void scan_graph(vector<vector<int>> &graph,
                int n) {  // graph - граф и n - количество рёбер
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        graph[v - 1].push_back(w - 1);
    }
}

int main() {}