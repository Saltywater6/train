#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll M=2e5+10;
ll m[M];
void solve(){
	ll n,f,a,b;
	cin>>n>>f>>a>>b;
	for(ll i=1;i<=n;++i)cin>>m[i];
	for(ll i=1;i<=n;++i){
		ll t=min((m[i]-m[i-1])*a,b);
		f-=t;
		if(f<=0){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";


}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll T=1;
	cin>>T;
	while(T--)solve();
}
