#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll a, b, c, d, v, t;
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &v, &t);
        ll loop = lcm(a, c);
        ll rest = t % loop;
        ll ans = 0;
        int cnt = 0, flg = 0;
        ll cur1 = a, cur2 = c, lst = 0;
        while (cur1 <= loop && cur2 <= loop) {
            ll cur = min(cur1, cur2);
            if (cur > rest && !flg) {
                ans += cnt;
                flg = 1;
            }
            if (cur - lst > v) {
                ++cnt;
            }
            if (cur1 == cur) {
                cur1 += a;
            }
            if (cur2 == cur) {
                cur2 += c;
            }
            lst = cur;
        }
        // printf("loop = %lld, cnt = %d, ans = %lld\n", loop, cnt, ans);
        ans += t / loop * cnt;
        ans += 1;
        ans = (t / a + 1) * b + (t / c + 1) * d - ans;
        printf("%lld\n", ans);
    }
    return 0;
}

