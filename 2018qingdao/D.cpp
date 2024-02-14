#include <bits/stdc++.h>

template <class T>
inline int qlog(T a) {
	double x = a;
	return ((*(long long*) & x) >> 52 & 2047) - 1023;
}

#define fopen LilyWhite
void fopen(const char *s) {
    static char filename[32];
    sprintf(filename, "%s.in", s);
    freopen(filename, "r", stdin);
    sprintf(filename, "%s.out", s);
    freopen(filename, "w", stdout);
}

typedef unsigned int u32;
typedef long long ll;
typedef unsigned long long u64;

#define Please return
#define AC 0
#define cin Mizuhashi
#define cout Parsee
#define endl '\n'

class Reader{
	private:
	    static const int BUF_SIZE = 1 << 22;
	    char BUF_R[BUF_SIZE], *csy1, *csy2;
	    #ifndef _LOCAL_RUNNING
		    #define GC (csy1 == csy2 && (csy2 = (csy1 = BUF_R) + fread(BUF_R, 1, BUF_SIZE, stdin), csy1 == csy2) ? EOF : *csy1 ++)
		#else
		    char cur;
		    #define GC (cur = getchar())
		#endif
	    #define IL inline
		
    public:
        IL bool eof() {
            #ifndef _LOCAL_RUNNING
                return csy1 == csy2 && (csy2 = (csy1 = BUF_R) + fread(BUF_R, 1, BUF_SIZE, stdin), csy1 == csy2);
            #else
                return cur == EOF;
            #endif
        }
        template <class Ty>
        IL Reader& operator >> (Ty &t) {
            int u = 0;
            char c = GC;
	    	for (t = 0; c < 48 || c > 57; c = GC)
                if (c == EOF) break;
                else if (c == '-') u = 1;
	    	for ( ; c > 47 && c < 58; c = GC) t = t * 10 + (c ^ 48);
	    	t = u ? -t : t; return *this;
        }
    	IL Reader& operator >> (double &t) {
            int tmp, u = 0; char c = GC;
	    	for (tmp = 0; c < 48 || c > 57; c = GC)
                if (c == EOF) break;
                else if (c == '-') u = 1;
	    	for ( ; c > 47 && c < 58; c = GC) tmp = tmp * 10 + (c ^ 48);
	    	t = (tmp = u ? -tmp : tmp);
    	    if (c == '.') {
    	        double x = 1;
    	        for (c = GC; c > 47 && c < 58; c = GC) t += (x /= 10) * (c ^ 48);
    	    }
    	    return *this;
    	}
    	IL Reader& operator >> (char *s) {
			char c = GC;
			for (*s = 0; c < 33; c = GC) if (c == EOF) return *this;
			for ( ; c > 32; c = GC) *s ++ = c;
			*s = 0; return *this;
		}
        IL Reader& operator >> (char &c) {
			for (c = GC; c < 33; c = GC) if (c == EOF) return *this;
            return *this;
        }
}cin;
class Writer{
	private:
	    static const int BUF_SIZE = 1 << 22;
	    char BUF_W[BUF_SIZE], *csy;
	    #define IL inline
		inline void WC(const char c) {
			if (csy - BUF_W == BUF_SIZE) fwrite(BUF_W, 1, BUF_SIZE, stdout), csy = BUF_W;
			*csy ++ = c;
		}
	
	public:
		Writer() : csy(BUF_W) {}
		~ Writer() {fwrite(BUF_W, 1, csy - BUF_W, stdout);}
		IL void flush() {fwrite(BUF_W, 1, csy - BUF_W, stdout); csy = BUF_W;}
		template <class Ty>
		IL Writer& operator << (Ty x) {
		    static int sta[32], top;
			if (x < 0) {
				WC('-');
                do sta[top ++] = - (x % 10); while (x /= 10);
			}else do sta[top ++] = x % 10; while (x /= 10);
			while (top) WC(sta[-- top] ^ 48);
			return *this;
		}
		IL Writer& operator << (const char &c) {WC(c); return *this;}
		IL Writer& operator << (const char *s) {while (*s) WC(*s ++); return *this;}
}cout;

using namespace std;

const int MAX_N = 100000 + 5;

int N, M, K, fath[MAX_N], tot, cnt, rec[MAX_N];
vector <pair <int, int> > d[MAX_N];
struct Hline{
    int r, c1, c2;
    Hline (int a = 0, int b = 0, int c = 0) : r(a), c1(b), c2(c) {}
    inline bool operator < (const Hline &comp) const {
        return r < comp.r || r == comp.r && c1 < comp.c1;
    }
};
struct Vline{
    int c, r1, r2;
    Vline (int arg1 = 0, int arg2 = 0, int arg3 = 0) : c(arg1), r1(arg2), r2(arg3) {}
    inline bool operator < (const Vline &comp) const {
        return r1 < comp.r1 || r1 == comp.r1 && c < comp.c;
    }
};
vector <Hline> h;
vector <Vline> v;
struct Node{
    int l, r, idx;
    inline bool operator < (const Node &comp) const {
        return l < comp.l || l == comp.l && idx < comp.idx;
    }
};
set <Node> s1, s2, t;

int Find(int x) {
    return x == fath[x] ? x : fath[x] = Find(fath[x]);
}

void Merge(int a, int b) {
    int x = Find(a), y = Find(b);
    if (x == y) return ;
    cnt --;
    fath[y] = x;
}

void modifyV(int l, int r, int idx) {
    s2.insert({l, r, idx});
    auto it = s1.upper_bound({l, 0, K});
    if (it != s1.begin()) it --;
    for ( ; it != s1.end(); it ++) {
        if (it -> r < l) continue;
        if (r < it -> l) break;
        Merge(it -> idx, idx);
    }
    for (it = t.lower_bound({l, 0, 0}); it != t.end(); it ++) {
        if (it -> r < l) continue;
        if (r < it -> l) break;
        Merge(it -> idx, idx);
    }
}

void modifyT(int p, int idx) {
    auto it = t.lower_bound({p, p, 0});
    if (it != t.end() && it -> l == p) Merge(it -> idx, idx);
    it = s1.upper_bound({p, 0, K});
    if (it != s1.begin()) it --;
    if (it != s1.end() && it -> r >= p && it -> l <= p) Merge(it -> idx, idx);
    it = s2.upper_bound({p, 0, K});
    if (it != s2.end() && it -> l == p + 1) Merge(it -> idx, idx);
    it = s2.lower_bound({p, 0, 0});
    if (it != s2.begin()) it --;
    if (it != s2.end() && it -> r == p - 1) Merge(it -> idx, idx);
    t.insert({p, p, idx});
}

void calc_row() {
    if (s2.empty()) return ;
    auto it1 = s2.begin();
    auto it2 = it1; it2 ++;
    auto it3 = t.lower_bound({it1 -> l, 0, 0});
    if (it3 != t.begin()) it3 --;
    if (it3 != t.end() && it3 -> l + 1 == it1 -> l) Merge(it3 -> idx, it1 -> idx);
    it3 = t.upper_bound({it1 -> r, 0, K});
    if (it3 != t.end() && it3 -> l == it1 -> r + 1) Merge(it3 -> idx, it1 -> idx);
    while (it2 != s2.end()) {
        if (it1 -> r + 1 == it2 -> l) Merge(it1 -> idx, it2 -> idx);
        it1 ++; it2 ++;
        it3 = t.upper_bound({it1 -> r, 0, K});
        if (it3 != t.end() && it3 -> l == it1 -> r + 1) Merge(it3 -> idx, it1 -> idx);
        it3 = t.lower_bound({it1 -> l, 0, 0});
        if (it3 != t.begin()) it3 --;
        if (it3 != t.end() && it3 -> l + 1 == it1 -> l) Merge(it3 -> idx, it1 -> idx);
    }
}

void solve() {
    tot = 0; cnt = 0;
    h.clear(); v.clear();
    s1.clear(); s2.clear(); t.clear();
    
    cin >> N >> M >> K;
    for (int i = 1; i <= K; i ++) {
        fath[i] = i;
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == r2) h.emplace_back(r1, c1, c2);
        else v.emplace_back(c1, r1, r2);
    }
    for (int i = 1; i <= N; i ++) d[i].clear();
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    ll ans1 = 0; int S = 0;
    for (int i = 1, ih = 0, iv = 0; i <= N; i ++) {
        for ( ; ih < h.size() && h[ih].r == i; ih ++) {
            ans1 += h[ih].c2 - h[ih].c1 + 1;
            cnt ++; modifyV(h[ih].c1, h[ih].c2, ++ tot);
        }
        int last_iv = iv;
        for ( ; iv < v.size() && v[iv].r1 == i; iv ++) {
            cnt ++; tot ++; S ++;
            d[v[iv].r2 + 1].emplace_back(v[iv].c, tot);
            modifyT(v[iv].c, tot);
            if (iv && v[iv - 1].r1 == i && v[iv - 1].c + 1 == v[iv].c) Merge(tot - 1, tot);
            rec[iv] = tot;
        }
        for (auto x : d[i]) t.erase({x.first, x.first, x.second});
        calc_row();
        for (int j = last_iv; j < iv; j ++) {
            auto it = t.lower_bound({v[j].c - 1, 0, 0});
            if (it != t.end() && it -> l + 1 == v[j].c) Merge(rec[j], it -> idx);
            it = t.lower_bound({v[j].c + 1, 0, 0});
            if (it != t.end() && it -> l - 1 == v[j].c) Merge(rec[j], it -> idx);
        }
        S -= d[i].size(); ans1 += S;
        cout << ans1 << ' ' << cnt << endl;
        s1 = s2; s2.clear();
    }
}

int main() {
    int T;
    cin >> T;
    while (T --) solve();
    return 0;
}

