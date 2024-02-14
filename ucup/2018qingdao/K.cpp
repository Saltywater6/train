#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100000 + 5;

int bkt[35];

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        memset(bkt, 0, sizeof bkt);
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            int lg2 = 0;
            while (x) {
                x >>= 1;
                ++lg2;
            }
            ++bkt[lg2];
        }
        int ans = *max_element(bkt, bkt + 35);
        printf("%d\n", ans);
    }
    return 0;
}
