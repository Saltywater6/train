#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>>A(n);
	for(auto &[a,b]:A)cin>>a;
	for(auto &[a,b]:A)cin>>b;
	int m;
	cin>>m;
	vector<pair<int,int>>B(m);
	for(auto& [a,b]:B)cin>>a;
	for(auto& [a,b]:B)cin>>b;
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	vector<int>sa(n),sb(m);
	for(int i=n-1;i>=0;--i){
		sa[i]=i;
		if(i<n-1&&A[sa[i+1]].second>A[i].second)
			sa[i]=sa[i+1];
	}
	for(int i=m-1;i>=0;--i){
		sb[i]=i;
		if(i<m-1&&B[sb[i+1]].second>B[i].second)
			sb[i]=sb[i+1];
	}
	vector<vector<int>> G(n+m);
	vector<int>ind(n+m);
	for(int i=0;i<n;++i){
		int t=lower_bound(B.begin(),B.end(),pair(A[i].second+1,0))-B.begin();
		if(t!=m)G[sb[t]+n].emplace_back(i),ind[i]++;
	}
	for(int i=0;i<m;++i){
		int t=lower_bound(A.begin(),A.end(),pair(B[i].second+1,0))-A.begin();
		if(t!=n)G[sa[t]].emplace_back(i+n),ind[i+n]++;
	}
	vector<int>ans(n+m,-1);
	queue<int>que;
	for(int i=0;i<n+m;++i)
		if(!ind[i]){
			ans[i]=i<n;
			que.push(i);
		}
	while(!que.empty()){
		int x=que.front();
		que.pop();
		for(int &y:G[x]){
			ans[y]=ans[x];
			if(!--ind[y])que.push(y);
		}
	}
	ans.resize(n);
	cout<<count(ans.begin(),ans.end(),1)<<" ";
	cout<<count(ans.begin(),ans.end(),-1)<<" ";
	cout<<count(ans.begin(),ans.end(),0)<<" ";
	cout<<"\n";
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}

	
