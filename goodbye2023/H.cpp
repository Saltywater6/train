#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int M=1e6+10,mod=998244353;
ll c[M];
ll n,p,k;
ll Pow(ll a,ll b){
	b=b%(mod-1);
	ll res=1;
	for(;b;b>>=1,a=a*a%mod){
		if(b&1)res=res*a%mod;
	}
	return res;
}
void solve(){
	cin>>n>>p>>k;
	ll ans=1;
	for(int i=0;i<=k;++i){
		if(i>n)ans=0;
		else if(i>0){
			ans=ans*Pow(p,i-1)%mod*Pow(Pow(p,n-i+1)-1,2)%mod;
			if(ans!=0)ans=ans*Pow(Pow(p,i)-1,mod-2)%mod;
		}
		cout<<ans<<" ";
	}

}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	while(T--)solve();
	return 0;
}

