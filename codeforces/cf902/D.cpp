#include<bits/stdc++.h>
using namespace std;

constexpr int mod=998244353;
void solve(){
	int n;
	cin>>n;
	vector<int>A(n),B(n),pw(n);
	for(auto &x:A)cin>>x;
	for(int i=0;i<n;++i)
		for(int j=i;j<n;j+=i+1)
			B[i]=max(B[i],A[j]);
	sort(B.begin(),B.end(),greater());
	for(int i=pw[0]=1;i<n;++i)
		pw[i]=pw[i-1]*2%mod;
	int ans=0;
	for(int i=0;i<n;++i)
		ans=(ans+1ll*pw[n-i-1]*B[i])%mod;
	cout<<ans<<"\n";
}	
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	//cin>>T;
	while(T--)solve();
}
