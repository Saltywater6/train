#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>>G(n),E(2*n);
	vector<ll>dis(n),vis(n),deg(n*2),f(n*2);
	vector<ll>a(n),b(n),v(n*2,-1e18);
	for(ll i=0;i<n;++i)
		cin>>a[i]>>b[i];
	for(ll i=0;i<m;++i){
		ll a,b;
		cin>>a>>b;
		--a,--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	queue<ll>que;
	que.emplace(0);
	vis[0]=1;
	ll mx=-1e18,smx=-1e18;
	while(!que.empty()){
		auto x=que.front();
		que.pop();
		if(a[x]-b[x]*(dis[x]+1)>smx)
			smx=a[x]-b[x]*(dis[x]+1);
		if(smx>mx)swap(smx,mx);
		for(auto y:G[x]){
			if(!vis[y]){
				vis[y]=1;
				dis[y]=dis[x]+1;
				que.emplace(y);
			}
		}
	}
	for(ll i=0;i<n;++i){
		for(auto j:G[i]){
			if(dis[j]==dis[i]+1){
				E[j].push_back(i),++deg[i];
				E[j+n].push_back(i+n),++deg[i+n];
			}else if(dis[i]==dis[j])
				E[j+n].push_back(i),++deg[i];
		}
	}
	for(ll i=0;i<n;++i){
		f[i]=a[i]-b[i]*(dis[i]-1);
		f[i+n]=f[i]-b[i];
	}
	for(ll i=0;i<2*n;++i)
		if(!deg[i])que.emplace(i);
	while(!que.empty()){
		auto x=que.front();
		que.pop();
		for(auto y:E[x]){
			v[y]=max(v[y],f[x]);
			v[y]=max(v[y],v[x]);
			if(--deg[y]==0){
				que.emplace(y);
			}
		}
	}
	sort(G[0].begin(),G[0].end());
	for(auto x:G[0])cout<<max(v[x],(mx==a[x]-b[x]*(dis[x]+1))?smx:mx)<<endl;
}
