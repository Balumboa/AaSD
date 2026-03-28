#include <bits/stdc++.h>

using namespace std;

void dfs(int v, bool& flag, vector<int>& used, vector<vector<int>>& graph,
         vector<int>& top_sorted_vertex) {
    if (used[v] != 0) {
        if (used[v] == -1) {
            flag = false;
        }
        return;
    }
    used[v] = -1;
    for (int i = 0; i < (int)graph[v].size(); i++) {
        int w = graph[v][i];
        dfs(w, flag, used, graph, top_sorted_vertex);
    }
    used[v] = 1;
    top_sorted_vertex.push_back(v);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        graph[v].push_back(w);
    }
    bool is_acyclic = true;
    vector<int> top_sorted_vertex;
    vector<int> used(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (used[i] == 0) {
            dfs(i, is_acyclic, used, graph, top_sorted_vertex);
        }
    }
    reverse(top_sorted_vertex.begin(), top_sorted_vertex.end());
    if (is_acyclic) {
        for (auto el : top_sorted_vertex) {
            cout << el << ' ';
        }
    } else {
        cout << -1;
    }
}
