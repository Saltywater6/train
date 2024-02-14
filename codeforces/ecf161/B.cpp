#include<bits/stdc++.h>
using namespace std;

using ll = long long ;

ll binom(int n){
	if(n<3)return 0;
	return 1ll*n*(n-1)*(n-2)/6;
}
void solve() {
	int n;
	cin>>n;
	vector<int>A(n+1);
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		A[x]++;
	}
	ll ans=0,s=0;
	for(int i=0;i<=n;++i)
		ans+=binom(A[i])+1ll*A[i]*(A[i]-1)/2*s,s+=A[i];
	cout<<ans<<"\n";
		
}

int main() {
	cin.tie()->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--) solve();
	return  0;
}

