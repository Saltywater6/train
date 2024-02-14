#include<bits/stdc++.h>
using namespace std;

constexpr int mod=1e9+7;
int power(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}

vector<vector<int>> operator *(vector<vector<int>> &a,
		vector<vector<int>> &b){
	int n=a.size();
	vector c(n,vector<int>(n));
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k)
				c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%mod;
	return c;
}
void solve(){
	int n,x,k;
	cin>>n>>x>>k;
	int ans=1ll*(x+k)*power((2*k+1)%mod,n-1)%mod;
	vector a(x,vector<int>(x)),res(x,vector<int>(x));
	for(int i=0;i<x;++i)
		for(int j=0;j<x;++j){
			a[i][j]=abs(i-j)<=k;
			res[i][j]=i==j;
		}
	for(int m=n-1;m;m>>=1,a=a*a)
		if(m&1)res=res*a;
	for(auto x:res)for(auto y:x)ans=(ans+mod-y)%mod;
	cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
