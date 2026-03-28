#include <bits/stdc++.h>

using namespace std;

void dfs_1(int v, vector<int>& used, vector<int>& tout_sorted,
           vector<vector<int>>& graph) {
    if (used[v] == 1) {
        return;
    }
    used[v] = 1;
    for (int i = 0; i < (int)graph[v].size(); i++) {
        int w = graph[v][i];
        dfs_1(w, used, tout_sorted, graph);
    }
    tout_sorted.push_back(v);
}

void dfs_2(int v, vector<int>& used, vector<vector<int>>& graph,
           vector<int>& answer, int num_comp) {
    if (used[v] == 1) {
        return;
    }
    used[v] = 1;
    answer[v] = num_comp;
    for (int i = 0; i < (int)graph[v].size(); i++) {
        int w = graph[v][i];
        dfs_2(w, used, graph, answer, num_comp);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<vector<int>> graph_reverse(N + 1);
    for (int i = 1; i <= M; i++) {
        int v, w;
        cin >> v >> w;
        graph[v].push_back(w);
        graph_reverse[w].push_back(v);
    }

    vector<int> tout_sorted;
    vector<int> used(N + 1);

    for (int i = 1; i <= N; i++) {
        if (used[i] == 0) {
            dfs_1(i, used, tout_sorted, graph);
        }
    }
    fill(used.begin(), used.end(), 0);
    reverse(tout_sorted.begin(), tout_sorted.end());
    vector<int> num_of_component(N + 1);
    int num_comp = 0;
    for (int v : tout_sorted) {
        if (used[v] == 0) {
            num_comp++;
            dfs_2(v, used, graph_reverse, num_of_component, num_comp);
        }
    }
    cout << num_comp << '\n';
    for (int i = 1; i <= N; i++) {
        cout << num_of_component[i] << ' ';
    }
}
