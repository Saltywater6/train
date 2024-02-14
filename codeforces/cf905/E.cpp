#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
const ll M=1e5+10;
ll A[M];
void solve(){
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&A[i]);
	ll ans=0,C=0;
	for(ll i=2;i<=n;++i){
		if(A[i]<A[i-1]){
			ll t=A[i];
			while(t<A[i-1])t=t*2,C++;
		}else{
			ll t=A[i-1];
			while(t<=A[i]&&C)t=t*2,C--;
			if(t>A[i])C++;
		}
		ans+=C;
	}
	printf("%lld\n",ans);
}
int main(){
	//freopen("hayasa","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
