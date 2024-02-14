#include<bits/stdc++.h>
using namespace std;

const int M=1e7+1;
vector<int>dig(M);
using ll=long long;
ll binom(int n,int m){
	ll res=1;
	for(int i=n;i>=n-m+1;--i)
		res=res*i;
	for(int i=1;i<=m;++i)
		res=res/i;
	return res;
}
void solve(){
	int n;
	cin>>n;
	if(n<100){
		int ans=0;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n-i;++j){
				int k=n-i-j;
				if(dig[i]+dig[j]+dig[k]==dig[n])
					ans++;
			}
		cout<<ans<<"\n";
	}else{
		ll ans=1;
		while(n)ans=ans*binom(n%10+2,2),n/=10;
		cout<<ans<<"\n";
	}
}

void init(){
	for(int i=1;i<M;++i)dig[i]=dig[i/10]+i%10;
}
	
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	init();
	while(T--)solve();
}
