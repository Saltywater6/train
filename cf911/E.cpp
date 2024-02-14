#include<bits/stdc++.h>
using namespace std;

using ll=long long ;
const ll M=2e5+10;
vector<int>G[M],B[M];
ll A[M],dfn[M],low[M],stk[M],pos[M];
ll tot,ans,top,sum[M],c[M];
ll ind[M],bcnt,f[M],g[M];
bool instk[M];
void dfs(ll x){
	dfn[x]=low[x]=++tot;
	stk[++top]=x;
	instk[x]=1;
	for(ll y:G[x]){
		if(!dfn[y])dfs(y),low[x]=min(low[x],low[y]);
		else if(instk[y])low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		ll y;
		++bcnt;
		do{
			y=stk[top--];
			instk[y]=0;
			pos[y]=bcnt;
			B[bcnt].push_back(y);
			sum[bcnt]+=A[y];
			c[bcnt]++;
		}while(y!=x);
	}
	
}	
void solve(){
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;++i) cin>>A[i];
	for(ll i=0;i<m;++i){
		ll a,b;
		cin>>a>>b;
		--a,--b;
		G[a].emplace_back(b);
	}
	for(ll i=0;i<n;++i)if(!dfn[i])dfs(i);
	queue<int>que;
	for(ll i=0;i<n;++i)
		for(ll y:G[i])
			if(pos[y]!=pos[i])++ind[pos[y]];
	for(ll i=1;i<=bcnt;++i)if(!ind[i])que.push(i);
	ll ans1=0,ans2=0;
	while(!que.empty()){
		ll x=que.front();
		que.pop();
		g[x]+=sum[x];
		f[x]+=c[x];
		if(ans1<f[x]||ans1==f[x]&&ans2>g[x])
			ans1=f[x],ans2=g[x];
		for(ll y:B[x]){
			for(ll z:G[y]){
				if(pos[z]==x)continue;
				//cout<<y<<" "<<z<<endl;
				if(f[pos[z]]<f[x]||f[pos[z]]==f[x]&&g[pos[z]]>g[x])
					f[pos[z]]=f[x],g[pos[z]]=g[x];
				if(--ind[pos[z]]==0){
					que.push(pos[z]);
				}
			}
		}
	}

	for(ll i=0;i<=n;++i)G[i].clear(),f[i]=g[i]=pos[i]=0,B[i].clear();
	for(ll i=0;i<=n;++i)sum[i]=c[i]=dfn[i]=low[i]=0;
	tot=bcnt=0;
	cout<<ans1<<" "<<ans2<<"\n";

}
int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	ll T=1;
	cin>>T;
	while(T--)solve();
}

