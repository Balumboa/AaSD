#include <bits/stdc++.h>

using namespace std;

vector<int> per(9);
vector<bool> not_use(9, true);

void rec(int now) {
    if (now == 9) {
        int sum1 = per[0] + per[1] + per[2];
        int sum2 = per[3] + per[4] + per[5];
        int sum3 = per[6] + per[7] + per[8];
        int sum4 = per[0] + per[3] + per[6];
        int sum5 = per[1] + per[4] + per[7];
        int sum6 = per[2] + per[5] + per[8];
        int sum7 = per[0] + per[4] + per[8];
        int sum8 = per[2] + per[4] + per[6];
        if (sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum5 &&
            sum5 == sum6 && sum6 == sum7 && sum7 == sum8) {
            for (int i = 0; i < 9; i++) {
                if (i % 3 == 0) {
                    cout << '\n';
                }
                cout << per[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (not_use[i]) {
            per[now] = i;
            not_use[i] = false;
            rec(now + 1);
            not_use[i] = true;
        }
    }
}

int main() {
    rec(0);
}