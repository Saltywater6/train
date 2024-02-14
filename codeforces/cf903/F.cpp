#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<bool>mk(n,0);
	for(int i=0;i<k;++i){
		int x;
		cin>>x;
		mk[--x]=1;
	}
	vector<vector<int>>G(n);
	for(int i=1;i<n;++i){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	if(k==1){
		cout<<"0\n";
		return ;
	}
	vector<int>f(n,-1),g(n,-1),h(n,-1),fr(n),gr(n);
	auto dfs = [&](auto self,int x,int fa)->void{
		if(mk[x])f[x]=0,fr[x]=x;
		for(int y:G[x])if(y!=fa){
			self(self,y,x);
			if(f[y]==-1)continue;
			if(f[y]+1>g[x])g[x]=f[y]+1,gr[x]=y;
			if(g[x]>f[x])swap(g[x],f[x]),swap(fr[x],gr[x]);
		}
	};
	dfs(dfs,0,-1);
	int ans=1e9;
	auto redfs = [&](auto self,int x,int fa)->void{
		ans=min(ans,max(f[x],h[x]));
		for(int y:G[x])if(y!=fa){
			if(y==fr[x])h[y]=max(h[x],g[x])+1;
			else h[y]=max(h[x],f[x])+1;
			if(h[y]==0)h[y]=-1;
			self(self,y,x);
		}
	};
	redfs(redfs,0,-1);
	cout<<ans<<"\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
