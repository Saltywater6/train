#include<bits/stdc++.h>
using namespace std;

const int mod1=1e9+7,mod2=1e9+9;
pair<int,int> power(int a,int b){
	int a1=a,a2=a;
	int r1=1,r2=1;
	for(;b;b>>=1){
		if(b&1){
			r1=1ll*r1*a1%mod1;
			r2=1ll*r2*a2%mod2;
		}
		a1=1ll*a1*a1%mod1;
		a2=1ll*a2*a2%mod2;
	}
	return pair(r1,r2);
}
int Pow(int a,int b,int P){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%P)
		if(b&1)res=1ll*res*a%P;
	return res;
}
void solve(){
	map<pair<int,int>,int>cnt;
	int n;
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		auto [a,b]=power(2,x);
		int c=Pow(x,mod1-2,mod1);
		int d=Pow(x,mod2-2,mod2);

		a=1ll*a*c%mod1;
		b=1ll*b*d%mod2;
		ans+=cnt[pair(a,b)];
		cnt[pair(a,b)]++;
	}
	cout<<ans<<"\n";

}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
