#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to;
    int weight;
};

void scan_graph(vector<vector<edge>>& graph, int m) {
    for (int i = 0; i < m; i++) {
        int v, w, weight;
        cin >> v >> w >> weight;
        graph[v].push_back({w, weight});
    }
}

void dfs(int v, vector<vector<edge>>& graph, vector<int>& sorted,
         vector<int>& used) {
    if (used[v] == 1) {
        return;
    }
    used[v] = 1;
    for (int i = 0; i < (int)graph[v].size(); i++) {
        int w = graph[v][i].to;
        dfs(w, graph, sorted, used);
    }
    sorted.push_back(v);
}

void top_sort(vector<vector<edge>>& graph, vector<int>& sorted, int N) {
    vector<int> used(N);
    for (int i = 1; i < N; i++) {
        dfs(i, graph, sorted, used);
    }
    reverse(sorted.begin(), sorted.end());
}

void solve(vector<vector<edge>>& graph, vector<int>& sorted, int s, int t) {
    vector<bool> used(graph.size(), false);
    vector<long long> r(graph.size(), 1e18);
    r[s] = 0;
    used[s] = true;
    for (int i = 0; i < (int)sorted.size(); i++) {
        int v = sorted[i];
        if (used[v] == true) {
            for (int j = 0; j < (int)graph[v].size(); j++) {
                int w = graph[v][j].to;
                used[w] = true;
                long long weight = graph[v][j].weight;
                r[w] = min(r[w], r[v] + weight);
            }
        }
    }
    if (!used[t])
        cout << "Unreachable\n";
    else
        cout << r[t] << '\n';
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<edge>> graph(n + 1);
    scan_graph(graph, m);
    vector<int> top_sorted;
    top_sort(graph, top_sorted, n + 1);
    solve(graph, top_sorted, s, t);
}