#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

const int MAX_N = 300000 + 5;

int N, M, a[MAX_N], b[MAX_N];
vector <int> ans1[MAX_N];

void solve() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i ++) scanf("%d", a + i);
    for (int i = 1; i <= M; i ++) scanf("%d", b + i);
    sort(a + 1, a + N + 1); sort(b + 1, b + M + 1);
    long long tot = 0;
    for (int i = N, j = M; j > 0; i --, j --) {
        ans1[i].clear();
        if (a[i] > b[j]) {
            fprintf(stderr, "-----\n");
            puts("-1"); return ;
        }
        tot += b[j] - a[i];
    }
    if (tot > N - M) {
        fprintf(stderr, "-----\n");
        puts("-1"); return ;
    }
    int rem = N - M - tot;
    vector <int> ans2(0);
    for (int i = N, j = M; j > 0; i --, j --) {
        for (int k = a[i]; k < b[j]; k ++) ans1[i].push_back(k);
        reverse(ans1[i].begin(), ans1[i].end());
    }
    int cur = 1;
    while (cur <= rem) {
        int p = upper_bound(a + 1, a + N + 1, a[cur]) - a - 1;
        ans2.push_back(a[cur ++]);
        if (p >= N - M + 1) {
            if (ans1[p].empty()) {
                fprintf(stderr, "-----\n");
                puts("-1"); return ;
            }
            ans1[p].pop_back();
            rem ++;
        }
        a[p] ++;
    }
    fprintf(stderr, "-----\n");
    printf("%d\n", N - M);
    for (auto x : ans2) printf("%d ", x);
    for (int i = N - M + 1; i <= N; i ++) {
        reverse(ans1[i].begin(), ans1[i].end());
        for (auto x : ans1[i]) printf("%d ", x);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) solve();
    return 0;
}
