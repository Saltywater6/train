#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200;
typedef vector <int> vi;

int N, M;
struct Vcomp{
    inline bool operator () (const vi &a, const vi &b) const {
        for (int i = 0; i < M; i ++)
            if (a[i] < b[i]) return 1;
            else if (b[i] < a[i]) return 0;
        return 0;
    }
};
set <vi, Vcomp> s;

vi operator + (const vi &a, const vi &b) {
    vi res(M);
    for (int i = 0; i < M; i ++) res[i] = a[b[i] - 1];
    return res;
}

int main() {
    scanf("%d%d", &M, &N);
    int fac = -1;
    if (N <= 11) {
        for (int i = 2; i <= N; i ++) fac *= i;
        fac = -fac;
    }
    for (int i = 1; i <= N; i ++) {
        vi a(M);
        for (int j = 0; j < M; j ++) scanf("%d", &a[j]);
        vector <vi> tmp(0);
        tmp.push_back(a);
        for (auto x : s) tmp.push_back(x + a);
        for (auto x : tmp) s.insert(x);
        if (s.size() == fac) break;
    }
    cout << s.size() << endl;
    return 0;
}
