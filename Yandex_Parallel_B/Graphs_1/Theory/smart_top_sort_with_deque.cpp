#include <bits/stdc++.h>

using namespace std;

void top_sort(vector<vector<int>>& graph, int n, vector<int>& sorted) {
    deque<int> deq;
    vector<int> step(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int v = graph[i][j];
            step[v]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (step[i] == 0)
            deq.push_back(i);
    }
    while (!deq.empty()) {
        int v = deq.back();
        sorted.push_back(v);
        deq.pop_back();
        for (int i = 0; i < graph[v].size(); i++) {
            int w = graph[v][i];
            step[w]--;
            if (step[w] == 0) {
                deq.push_back(w);
            }
        }
    }
}