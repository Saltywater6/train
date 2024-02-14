#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll =long long ;
const int N=6e5+10;
	struct edge {
		int v, nxt, cap;
	} e[N];

	int fir[N], cnt = 0;
	int n, S, T;
	ll maxflow = 0;
	int dep[N], cur[N];
	int c1,c2;
	bool vis[N];
	void init(int nn) {
		c1=0,c2=0;
		cnt = 0;
		S=2*nn+1,T=2*nn+2;
		n=T;
		maxflow=0;
		memset(fir, -1, sizeof (int)*(n+1));
	}

	void addedge(int u, int v, int w) {
		e[cnt] = {v, fir[u], w};
		fir[u] = cnt++;
		e[cnt] = {u, fir[v], 0};
		fir[v] = cnt++;
	}
	int q[N];
	bool bfs() {
		int L=1,R=0;
		memset(dep, 0, sizeof(int) * (n + 1));
		dep[S] = 1;
		q[++R]=S;
		while (L<=R) {
			int u = q[L++];
			for (int i = fir[u]; ~i; i = e[i].nxt) {
				int v = e[i].v;
				if ((!dep[v]) && (e[i].cap )) {
					dep[v] = dep[u] + 1;
					q[++R]=v;
				}
			}
		}
		return dep[T];
	}

	int dfs(int u, int flow) {
		if ((u == T) || (!flow)) return flow;
		int ret = 0;
		for (int& i = cur[u]; ~i; i = e[i].nxt) {
			int v = e[i].v, d;
			if ((dep[v] == dep[u] + 1) &&
					(d = dfs(v, min(flow - ret, e[i].cap )))) {
				ret += d;
				e[i].cap-= d;
				e[i ^ 1].cap+= d;
				if (ret == flow) return ret;
			}
		}
		return ret;
	}

	void dinic() {
		while (bfs()) {
			memcpy(cur, fir, sizeof(int) * (n + 1));
			maxflow += dfs(S, n);
		}
	}
	void dfs1(int x){
		if(vis[x])return ;
		vis[x]=1;
		if(x<n/2)++c1;
		for(int i=fir[x];~i;i=e[i].nxt){
			if(e[i].cap==0)continue;
			dfs1(e[i].v);
		}
	}
	void dfs2(int x){
		if(vis[x])return ;
		vis[x]=1;
		if(x>=n/2&&x<=n-2)++c2;
		for(int i=fir[x];~i;i=e[i].nxt){
			if(e[i].cap==1)continue;
			dfs2(e[i].v);
		}
	}
	void getans(){
		if(maxflow==n/2-1){
			printf("0\n");
			return ;
		}
		memset(vis,0,sizeof (bool)*(n+1));
		dfs1(S);
		memset(vis,0,sizeof (bool)*(n+1));
		dfs2(T);
		printf("%lld\n",1ll*c1*c2);
	}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=1;i<=n;++i){
		addedge(S,i,1);
		addedge(i+n,T,1);
	}
	for(int i=1;i<=m;++i){
		int a,b;	
		scanf("%d%d",&a,&b);
		addedge(a,b+n,1);
	}
	dinic();
	getans();
}

int main(){
	//cin.tie(0)->sync_with_stdio(0);
	//freopen("hayasa","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
