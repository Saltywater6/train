#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll>A(n),B(m);
	for(ll i=0;i<n;++i)cin>>A[i];
	for(ll i=0;i<m;++i)cin>>B[i];
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	A.insert(A.begin(),0);
	B.insert(B.begin(),0);
	for(ll i=1;i<A.size();++i)
		A[i]+=A[i-1];
	for(ll i=1;i<B.size();++i)
		B[i]+=B[i-1];
	ll ans=0;
	for(ll i=1;i<=n+1;++i)
		ans=max(ans,B[m]-B[m-i+1]-A[i-1]+A[n]-A[i-1]-B[n-i+1]);
	cout<<ans<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll T=1;
	cin>>T;
	while(T--)solve();
}
