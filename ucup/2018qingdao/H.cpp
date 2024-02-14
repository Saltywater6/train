#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100000 + 5;

using ll = long long;

int n;
char li[SIZE];

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", li + 1);
        n = strlen(li + 1);
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += (li[i] == '1' ? 1 : 2) * (n - i + 1);
            ans += (ll)(li[i] == li[i - 1] ? 2 : 1) * (i - 1) * (n - i + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
