#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<array<int,2>> A(n);
	for(int i=0;i<n;++i)
		cin>>A[i][0],A[i][1]=i;
	sort(A.begin(),A.end(),greater());
	vector<int>B(m);
	for(auto &x:B)cin>>x;
	vector f(m,vector<int>(n));
	for(int i=0;i<m;++i){
		int r=0;
		for(int l=0;l<n;++l){
			while(r<n&&A[r][0]*(r-l+1)<B[i])r++;
			f[i][l]=r;
		}
	}
	int S=(1<<m)-1;
	vector<int>dp(S+1,-1),pre(S+1);
	for(int i=0;i<S;++i)
		for(int j=0;j<m;++j){
			if(1<<j&i)continue;
			if(dp[i]==n||dp[i]==n-1||i&&dp[i]==-1)continue;
			//cout<<i<<" "<<dp[i]<<endl;
			if(dp[1<<j|i]==-1||dp[1<<j|i]>f[j][dp[i]+1]){
				dp[1<<j|i]=f[j][dp[i]+1];
				pre[1<<j|i]=j;
			}
		}
	//cout<<dp[S]<<endl;
	if(dp[S]<n&&dp[S]>=0){
		vector<vector<int>> ans(m);
		while(S){
			int x=pre[S],s=S^(1<<x);
			for(int i=dp[s]+1;i<=dp[S];++i)
				ans[x].emplace_back(A[i][1]);
			S=s;
		}
		cout<<"YES\n";
		for(int i=0;i<m;++i){
			cout<<ans[i].size()<<" ";
			for(auto x:ans[i])cout<<x+1<<" ";
			cout<<"\n";
		}
	}else cout<<"NO\n";
	
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	//cin>>T;
	while(T--)solve();
}
