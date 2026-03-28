#include <bits/stdc++.h>

using namespace std;

struct para {
    int time;
    int num;
};

void dfs(int v, vector<vector<int>> &graph, vector<para> &for_sorted,
         vector<int> &tout, vector<int> &tin, bool &cicle, int time) {
    if (cicle || tin[v] != -1) {
        cicle = true;
        return;
    }
    tin[v] = time;
    for (int i = 0; i < graph[v].size(); i++) {
        int w = graph[v][i];
        time++;
        dfs(w, graph, for_sorted, tout, tin, cicle, time);
    }

    if (cicle)
        return;

    time++;
    tout[v] = time;
    for_sorted.push_back({time, v});
}

void stpd_top_sort(vector<vector<int>> &graph, int n, vector<int> &top_sorted) {
    vector<int> tin(n, -1);
    vector<int> tout(n, -1);
    vector<para> for_sorted;
    int time = 0;
    bool cicle = false;
    for (int i = 0; i < n; i++) {
        if (tout[i] == -1) {
            dfs(i, graph, for_sorted, tout, tin, cicle, time);
        }
    }
    sort(for_sorted.rbegin(), for_sorted.rend());
    for (int i = 0; i < n; i++) {
        top_sorted[i] = for_sorted[i].num;
    }
}
