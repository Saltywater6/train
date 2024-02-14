#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500000 + 5;

int N, M, a[MAX_N], b[MAX_N], lst[MAX_N], c[MAX_N];

void modify(int x, int v) {
    for (int i = x; i <= N; i += i & -i) c[i] += v;
}

int query(int l, int r) {
    l --;
    int res = 0;
    while (l < r) {
        res += c[r];
        r -= r & -r;
    }
    while (r < l) {
        res -= c[l];
        l -= l & -l;
    }
    return res;
}

void solve() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", a + i); b[i] = a[i];
    }
    sort(b + 1, b + N + 1);
    int t = unique(b + 1, b + N + 1) - b - 1;
    for (int i = 1; i <= N; i ++) {
        a[i] = lower_bound(b + 1, b + t + 1, a[i]) - b;
    }
    int mex = 1;
    for (int i = 1; i <= t && b[i] == mex; i ++) mex ++;
    for (int i = 1; i <= t; i ++) lst[b[i]] = 0;
    memset(c, 0, sizeof(int) * (N + 1));
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= N; i ++) {
        if (lst[b[a[i]]]) modify(lst[b[a[i]]], -1);
        modify(lst[b[a[i]]] = i, 1);
        if (i == N) {
            for (int j = 1; j < mex; j ++) {
                if (j != b[a[i]])
                    ans = max(ans, query(lst[j] + 1, i) - j);
            }
            ans = max(ans, query(1, N) - mex);
        }else if (b[a[i + 1]] <= mex) {
            ans = max(ans, query(lst[b[a[i + 1]]] + 1, i) - b[a[i + 1]]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) solve();
    return 0;
}
