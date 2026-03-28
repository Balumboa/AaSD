#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>> &graph, vector<int> &sorted,
         vector<int> check, bool &cicle) {
    if (check[v] == 1 || cicle) {
        cicle = true;
        return;
    }
    check[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        if (check[v] < 2) {
            dfs(graph[v][i], graph, sorted, check, cicle);
        }
    }

    if (cicle) {
        return;
    }

    check[v] = 2;
    sorted.push_back(v);
}

void smart_top_sort(vector<vector<int>> &graph, int n, vector<int> &sorted) {
    bool cicle = false;
    vector<int> check(n, 0);
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            dfs(i, graph, sorted, check, cicle);
        }
    }
    reverse(sorted.begin(), sorted.end());
}