#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
struct node{
	int r,id;
	bool operator <(const node &_)const {
		return r<_.r||r==_.r&&id<_.id;
	}
};
int lg[M],n,m,q;
int dp[12][M],B[12][M];
int f[22][12][M];
void upd(int x,int y,int v){
	f[0][x][y]=v;
	for(int j=1;j<=20;++j)
		if(y-(1<<(j-1))>=0)
			f[j][x][y]=max(f[j-1][x][y],f[j-1][x][y-(1<<j-1)]);
		else f[j][x][y]=f[j-1][x][y];
}
void init(){
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int k=0;k<=q;++k){
		dp[k][0]=0,upd(k,0,0);
		for(int i=1;i<=n;++i)
			dp[k][i]=-1e9,upd(k,i,dp[k][i]);
	}
}
int qry(int l,int r,int k){
	if(l>r)return -1e9;
	int t=lg[r-l+1];
	return max(f[t][k][l+(1<<(t))-1],f[t][k][r]);
}
vector<node>G[M],T[M];
void Clear(){
	for(int i=1;i<=n;++i)
		G[i].clear(),T[i].clear(),B[0][i]=0;
}
set<node>st;
void solve(){
	scanf("%d%d%d",&n,&m,&q);
	init();
	for(int i=1;i<=m;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		G[r].push_back((node){l,i});
		T[l].push_back((node){l,i});
	}
	for(int i=1;i<=n;++i){
		for(auto x:T[i])st.insert(x);
		if(st.size()<=q){
			for(auto it:st)
				B[++B[0][i]][i]=it.r;
		}else B[0][i]=-1;
		for(auto x:G[i])st.erase(x);
	}
	for(int k=0;k<=q;++k)
		for(int i=1;i<=n;upd(k,i,dp[k][i]),++i){
			if(B[0][i]==-1)continue;
			if(B[0][i]==0){
				dp[k][i]=qry(0,i-1,k)+1;
				continue;
			}
			if(k>=B[0][i])dp[k][i]=max(dp[k][i],qry(0,B[1][i]-1,k-B[0][i])+1);
			for(int j=1;j<B[0][i];++j)
				if(k-B[0][i]+j>=0)dp[k][i]=max(dp[k][i],qry(B[j][i],B[j+1][i]-1,k-B[0][i]+j)+1);
			dp[k][i]=max(dp[k][i],qry(B[B[0][i]][i],i-1,k)+1);
		}
	int ans=0;
	for(int k=0;k<=q;++k)
		for(int i=1;i<=n;++i)
			ans=max(ans,dp[k][i]);
	printf("%d\n",ans);
	Clear();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
}
			
	
				
