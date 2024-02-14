#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;

constexpr ll M=2e5+10,mod=998244353;

vector<int>G[M];
ll fac[M],ifac[M],sz[M];
ll f[M][50];

ll binom(ll n,ll m){
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

void dfs(ll x){
	for(auto y:G[x])dfs(y);
	for(ll i=0;i<50;++i)f[x][i]=1;
	static ll g[50];
	for(auto y:G[x]){
		for(ll i=0;i<50;++i)
			for(ll j=1;i+j<50;++j)
				g[i+j-1]=(g[i+j-1]+1ll*binom(sz[x]+sz[y]+i+j-1,sz[y]+j-1)*f[x][i]%mod*f[y][j])%mod;
		memcpy(f[x],g,sizeof g);
		memset(g,0,sizeof g);
		sz[x]+=sz[y];
	}
	sz[x]++;

}

void init(){
	for(ll i=fac[0]=1;i<M;++i)fac[i]=fac[i-1]*i%mod;
	ifac[0]=ifac[1]=1;
	for(ll i=2;i<M;++i)ifac[i]=(mod-mod/i)*ifac[mod%i]%mod;
	for(ll i=2;i<M;++i)ifac[i]=ifac[i]*ifac[i-1]%mod;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	init();
	ll n;
	cin>>n;
	for(ll i=1;i<n;++i){
		ll x;
		cin>>x;
		G[x-1].push_back(i);
	}
	dfs(0);
	cout<<f[0][1]<<endl;
}
