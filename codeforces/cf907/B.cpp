#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll M=1e5+10;
ll A[M],stk[M],top;
void solve(){
	ll n,q;
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&A[i]);
	stk[0]=31,top=0;
	for(ll i=1;i<=q;++i){
		ll x;
		scanf("%lld",&x);
		if(x<stk[top])stk[++top]=x;
	}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=top;++j)
			if(A[i]%(1<<stk[j])==0)
				A[i]+=1<<(stk[j]-1);
	for(ll i=1;i<=n;++i)
		printf("%lld ",A[i]);
	puts("");
}
int main(){
	//freopen("hayasa","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
}
	
