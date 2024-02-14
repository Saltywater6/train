#include <bits/stdc++.h>

template <class T>
inline int qlog(T a) {
	double x = a;
	return ((*(long long*) & x) >> 52 & 2047) - 1023;
}
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAX_N = 1000000 + 5;
const int INF32 = 1e9;

int N, a[MAX_N], p[MAX_N], sum[MAX_N];
unordered_map <ll, int> cnt;

inline ll encode(int i, int j) {
    return 1ll * i * (N + 1) + j;
}

inline pii decode(ll x) {
    return {x / (N + 1), x % (N + 1)};
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    sum[0] = 0; cnt.clear();
    int maxv[2] = {-INF32, -INF32}, minv[2] = {INF32, INF32}, maxp[2], minp[2];
    for (int i = 1, j = 0, k = 0; i <= N; i ++) {
        sum[i] = sum[i - 1];
        if (maxv[0] < p[i]) {
            maxv[1] = maxv[0];
            maxp[1] = maxp[0];
            maxv[0] = p[i];
            maxp[0] = i;
        }else if (maxv[1] < p[i]) {
            maxv[1] = p[i];
            maxp[1] = i;
        }
        if (p[i] < minv[0]) {
            minv[1] = minv[0];
            minp[1] = minp[0];
            minv[0] = p[i];
            minp[0] = i;
        }else if (p[i] < minv[1]) {
            minv[1] = p[i];
            minp[1] = i;
        }
        if (maxv[0] - minv[0] + 1 == i) {
            sum[i] ++;
            if (i > 1) {
                if (minv[0] > 1) cnt[encode(a[maxv[0]], a[minv[0] - 1])] ++;
                if (maxv[0] < N) cnt[encode(a[minv[0]], a[maxv[0] + 1])] ++;
            }
            continue;
        }
        if (maxv[0] - minv[1] + 1 == i) {
            for (j = max(j, i + 1); p[j] < minv[1] || p[j] > maxv[0]; j ++);
            cnt[encode(minp[0], j)] ++;
        }else if (maxv[0] - minv[1] + 1 == i - 1) {
            cnt[encode(minp[0], a[minv[1] - 1])] ++;
            if (maxv[0] < N) cnt[encode(minp[0], a[maxv[0] + 1])] ++;
        }
        if (maxv[1] - minv[0] + 1 == i) {
            for (k = max(k, i + 1); p[k] < minv[0] || p[k] > maxv[1]; k ++);
            cnt[encode(maxp[0], k)] ++;
        }else if (maxv[1] - minv[0] + 1 == i - 1) {
            cnt[encode(maxp[0], a[maxv[1] + 1])] ++;
            if (minv[0] > 1) cnt[encode(maxp[0], a[minv[0] - 1])] ++;
        }
    }
    sum[0] = 1;
    pii ansp = {1, 1}; int ansc = 0;
    for (auto [code, c] : cnt) {
        pii p = decode(code);
        int tmp = c + sum[p.first - 1] - sum[p.second - 1];
        if (ansc < tmp) {
            ansc = tmp;
            ansp = p;
        }
    }
    cout << p[ansp.first] << ' ' << p[ansp.second] << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T --) solve();
    return 0;
}
