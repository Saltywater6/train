#include<bits/stdc++.h>
using namespace std;

vector<int>ans,A,ind;
void dfs(int x){
	ind[x]=-1;
	if(ans[x]){
		if(ind[A[x]]>=0){
			ans[A[x]]=0;
			dfs(A[x]);
		}
	}else{
		if(--ind[A[x]]==0){
			ans[A[x]]=1;
			dfs(A[x]);
		}
	}
}
void solve(){
	int n;
	cin>>n;
	A.resize(n);
	ans.resize(n);
	ind.resize(n);
	for(auto &x:A)cin>>x,++ind[--x];
	vector<vector<int>>G(n);
	for(int i=0;i<n;++i)G[A[i]].push_back(i);
	for(int i=0;i<n;++i)if(ind[i]==0)ans[i]=1,dfs(i);
	for(int i=0;i<n;++i)if(ind[i]>=0){
		int t=0,p=i;
		while(ind[p]>=0){
			ans[p]=t;
			ind[p]=-1;
			t=1-t;
			p=A[p];
		}
	}
	for(int i=0;i<n;++i){
		bool flag=0;
		for(auto y:G[i])
			if(ans[y])flag=1;
		if(flag==ans[i]){
			cout<<"-1\n";
			return ;
		}
	}

	vector<int> B;
	for(int i=0;i<n;++i)if(ans[i])B.push_back(A[i]+1);
	cout<<B.size()<<"\n";
	for(auto x:B)cout<<x<<" ";
	cout<<"\n";
}	
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	//cin>>T;
	while(T--)solve();
}
