#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;

constexpr int mod=998244353,M=2505;
int dp[M][M];
void solve(){
	int n,L;
	cin>>n>>L;
	for(int i=0;i<L;++i)dp[0][i]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<=L;++j)
			for(int k=0;i+(j+1)*(k+1)<=n&&j+k+1<=L;++k){
				(dp[i+(j+1)*(k+1)][k]+=dp[i][j])%=mod;
			}
	int ans=0;
	for(int i=0;i<=L;++i)ans=(ans+dp[n][i])%mod;
	cout<<ans<<endl;
	for(int i=0;i<=n;++i)for(int j=0;j<=L;++j)dp[i][j]=0;

}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
