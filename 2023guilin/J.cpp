#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef vector <int> vi;

const int MAX_N = 1000000 + 5;
const int Base1 = 233;
const int Base2 = 567;
const int Mod1 = 1258489069;
const int Mod2 = 1453570957;
void init();

int N, M, pw1[MAX_N], pw2[MAX_N];
char str[MAX_N];
string s[MAX_N], t[MAX_N];
int ids[MAX_N], idt[MAX_N];
struct Hash{
    vector <int> ha1, ha2;
    
    void build(const char *s) {
        ha1.resize(M + 1);
        ha2.resize(M + 1);
        ha1[0] = ha2[0] = 0;
        for (int i = 1; i <= M; i ++) {
            ha1[i] = (1ll * ha1[i - 1] * Base1 + s[i]) % Mod1;
            ha2[i] = (1ll * ha2[i - 1] * Base2 + s[i]) % Mod2;
        }
    }
    
    pii get(int l, int r) {
        int res1 = (ha1[r] - 1ll * ha1[l - 1] * pw1[r - l + 1] + 1ll * Mod1 * Mod1) % Mod1;
        int res2 = (ha2[r] - 1ll * ha2[l - 1] * pw2[r - l + 1] + 1ll * Mod2 * Mod2) % Mod2;
        return {res1, res2};
    }
}has[MAX_N], hat[MAX_N];
vector <pii> edge[MAX_N << 2];
int ecur[MAX_N<<2],ind[MAX_N<<2];
vi ans;

inline bool cmp_s(int i, int j) {return s[i] < s[j];}
inline bool cmp_t(int i, int j) {return t[i] < t[j];}

void dfs(int u) {
    for (int &i = ecur[u]; i < edge[u].size(); ) {
		int t=edge[u][i].second;
        dfs(edge[u][i++].first);
        ans.push_back(t);
    }
}

bool solve_graph(int tot) {
    ans.clear();
    for (int i = 1; i <= tot; i ++) ecur[i] = 0;
	for(int i=1;i<=tot;++i)
		if(ind[i]!=edge[i].size())return false;
    dfs(1);
    for (int i = 1; i <= tot; i ++)
        if (ecur[i] != edge[i].size()) return false;
    vi anss(0), anst(0);
	reverse(ans.begin(),ans.end());
    for (auto x : ans)
        if (x <= N) anss.push_back(x);
        else anst.push_back(x - N);
    for (int i = 0; i < anss.size(); i ++) printf("%d%c", anss[i], "\n "[i + 1 < M]);
    for (int i = 0; i < anst.size(); i ++) printf("%d%c", anst[i], "\n "[i + 1 < M]);
    return true;
}

void solve() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i ++) {
        ids[i] = i;
        idt[i] = i;
        scanf("%s", str + 1);
        has[i].build(str);
        s[i].resize(M + 1);
        s[i][0] = 0;
        for (int j = 1; j <= M; j ++) s[i][j] = str[j];
    }
    for (int i = 1; i <= N; i ++) {
        scanf("%s", str + 1);
        hat[i].build(str);
        t[i].resize(M + 1);
        t[i][0] = 0;
        for (int j = 1; j <= M; j ++) t[i][j] = str[j];
    }
    sort(ids + 1, ids + N + 1, cmp_s);
    sort(idt + 1, idt + N + 1, cmp_t);
    char flag = 1;
    for (int i = 1; i <= N; i ++)
        if (s[ids[i]] != t[idt[i]]) {
            flag = 0; break;
        }
    if (flag) {
        for (int i = 1; i <= N; i ++) printf("%d%c", ids[i], "\n "[i < N]);
        for (int i = 1; i <= N; i ++) printf("%d%c", idt[i], "\n "[i < N]);
        return ;
    }
    for (int i = 1; i < M; i ++) {
        int tot = 0;
        map <pii, int> idxs,idxt;
        for (int j = 1; j <= N * 4; j ++) edge[j].clear(),ind[j]=0;
        for (int j = 1; j <= N; j ++) {
            pii sj1 = has[j].get(1, i), sj2 = has[j].get(i + 1, M);
            pii tj1 = hat[j].get(1, M - i), tj2 = hat[j].get(M - i + 1, M);
            #define allocate(idx, x) (idx.count(x) ? idx[x] : (idx[x] = ++ tot))
            int u1 = allocate(idxs, sj1), v1 = allocate(idxt, sj2);
            int u2 = allocate(idxt, tj1), v2 = allocate(idxs, tj2);
            #undef allocate
            edge[u1].emplace_back(v1, j),++ind[v1];
            edge[u2].emplace_back(v2, j + N),++ind[v2];
        }
        if (solve_graph(tot)) {
            return ;
        }
    }
    puts("-1");
}

int main() {
	//freopen("hayasa","r",stdin);
    init();
    int T;
    scanf("%d", &T);
	for(int i=1;i<=T;++i){
		solve();
	}
    return 0;
}

void init() {
    pw2[0] = 1; pw1[0] = 1;
    for (int i = 1; i < MAX_N; i ++) {
        pw1[i] = 1ll * pw1[i - 1] * Base1 % Mod1;
        pw2[i] = 1ll * pw2[i - 1] * Base2 % Mod2;
    }
}

