#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=1e5+10;
ll fail[M],A[M],fir[M];
bool mk[M];
set<int>st;
void solve(){
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&A[i]);
	st.clear();
	for(ll i=1;i<=n;++i){
		fir[i]=fir[i-1];
		if(st.find(A[i])==st.end())
			++fir[i];
		st.insert(A[i]);
	}
	st.clear();
	ll ans=0;
	for(ll i=n;i;--i){
		if(st.find(A[i])==st.end())
			ans+=fir[i];
		st.insert(A[i]);
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	//freopen("hayasa","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
