#include<bits/stdc++.h>
using namespace std;

vector<int>ans,res;
const int M=605;
int n,m;
int g[M],f[M],p[M][M],a[M];
bool check(){
	for(int i=1;i<=n;++i)g[i]=f[i];
	ans.clear();
	for(int i=1;i<=m;++i){
		int c=0;
		for(int j=1;j<=n;++j){
			int t=p[i][j];
			if(g[t]==1){
				g[t]=2,c++;
				ans.push_back(t);
			}
			if(g[t]==0){
				g[t]=-1;
				break;
			}
		}
		if(ans.size()>a[i])return 0;
	}
	res=ans;
	return 1;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			cin>>p[i][j];
	for(int i=1;i<=n;++i){
		f[i]=1;
		if(!check())f[i]=0;
	}
	for(int x:res)cout<<x<<" ",f[x]=0;
	for(int i=1;i<=n;++i)if(f[i]==1)cout<<i<<" ";

	return 0;
}


