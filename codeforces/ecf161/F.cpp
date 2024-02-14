#include<bits/stdc++.h>
using namespace std;

using ll = long long ;

const int M=105;
int col[M];
int f[M][M][M],g[M][M][M],A[M];
void solve() {

	int n,x;
	cin>>n>>x;
	int ans=1e9;
	for(int i=1;i<=n;++i)cin>>A[i];
	if(x==1){
		cout<<"0\n";
		return ;
	}

	for(int L=1;L<=n;++L){
		for(int i=1;i<=x;++i)col[i]=0;
		int C=x;
		for(int R=L;R<=n;++R){
			for(int k=1;k<=x;++k)
				f[L][R][k]=g[L][R][k]=1e9;
			if(col[A[R]]==0)C--;	
			col[A[R]]=1;
			if(C){
				for(int k=1;k<=x;++k)
					if(col[k])g[L][R][k]=1;
					else g[L][R][k]=0;
			}
			if(C==x-1){
				for(int k=1;k<=x;++k)
					if(col[k])f[L][R][k]=0;
			}
		}
	}
	for(int L=n;L;--L)
		for(int R=L;R<=n;++R){
			int mn=1e9,smn=1e9;
			for(int k=1;k<=x;++k){
				for(int i=L;i<R;++i){
					f[L][R][k]=min(f[L][R][k],f[L][i][k]+f[i+1][R][k]);
					g[L][R][k]=min(g[L][R][k],g[L][i][k]+g[i+1][R][k]);
				}
				g[L][R][k]=min(g[L][R][k],f[L][R][k]+1);
				f[L][R][k]=min(f[L][R][k],g[L][R][k]+1);
				if(f[L][R][k]<smn)smn=f[L][R][k];
				if(smn<mn)swap(smn,mn);
			}
			for(int k=1;k<=x;++k){
				g[L][R][k]=min(g[L][R][k],mn==f[L][R][k]?smn:mn);
				f[L][R][k]=min(f[L][R][k],g[L][R][k]+1);
				if(L==1&&R==n)ans=min(ans,f[L][R][k]);
			}
		}
	cout<<ans<<"\n";
}

int main() {
	cin.tie()->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--) solve();
	return  0;
}

