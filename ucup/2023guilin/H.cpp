#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
void solve();
int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--)solve();
}

const int N=1e6+3;
struct edge{int to,nxt;}e[N<<1];
int lst[N],tt;
void add(int u,int v){
	e[++tt].to=v;
	e[tt].nxt=lst[u];
	lst[u]=tt;
}
int c[N];
int ds[N],sm[N],g[N],n,k;
//sm: -1  已选
void dfs(int u,int f){
	g[u]=0;
	int sum=c[u],mds=1e9;
	for(int i=lst[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f)continue;
		dfs(v,u);
		if(sm[v]!=-1){
			sum+=sm[v];
			mds=min(mds,ds[v]);
		}
		g[u]+=g[v];
	}
	if(sum-mds>=k-1||sum>=k&&((sum^k)&1)==0){
		// cout<<"@@"<<u<<" "<<sum<<" "<<k<<" "<<mds<<endl;
		sm[u]=-1;
		g[u]++;
		return;
	}
	sm[u]=sum;
	ds[u]=mds;
	if(c[u]==1)ds[u]=min(ds[u],sm[u]);
}
void solve(){
	cin>>n>>k;
	tt=0;
	for(int i=1;i<=n;i++)lst[i]=0;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		add(u,v);add(v,u);
	}
	dfs(1,0);
	cout<<g[1]<<endl;
}
