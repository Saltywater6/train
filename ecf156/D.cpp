#include<bits/stdc++.h>
using namespace std;

const int M=3e5+10,mod=998244353;
vector<int>inv(M);
void solve(){
	string s;
	int n,m;
	cin>>n>>m>>s;
	int ans=1;
	for(int i=1;i<n;++i)
		if(s[i]=='?')ans=1ll*ans*i%mod;
	if(s[0]=='?')cout<<"0\n";
	else cout<<ans<<"\n";
	while(m--){
		string t;
		int x;
		cin>>x>>t;
		--x;
		if(x){
			if(s[x]=='?')ans=1ll*ans*inv[x]%mod;
			if(t[0]=='?')ans=1ll*ans*x%mod;
		}
		s[x]=t[0];
		if(s[0]=='?')cout<<"0\n";
		else cout<<ans<<"\n";
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	//cin>>T;
	inv[1]=1;
	for(int i=2;i<M;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	while(T--)solve();
}
