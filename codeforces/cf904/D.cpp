#include<bits/stdc++.h>
using namespace std;

using ll=long long ;
void solve(){
	ll n;
	cin>>n;
	vector<ll>f(n+1),g(n+1);
	for(ll i=1;i<=n;++i){
		ll x;
		cin>>x;
		f[x]++;
		g[x]=1;
	}
	for(ll i=1;i<=n;++i){
		for(ll j=2*i;j<=n;j+=i)
			f[i]+=f[j],g[j]|=g[i];
		f[i]=f[i]*(f[i]-1)/2;
	}
	for(int i=n;i;--i)
		for(ll j=2*i;j<=n;j+=i)
			f[i]-=f[j];
	ll ans=0;
	for(ll i=1;i<=n;++i)
		if(!g[i])ans+=f[i];
	cout<<ans<<endl;
}
int main(){
	//freopen("hayasa","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll T;
	cin>>T;
	while(T--)solve();
	return 0;
}
