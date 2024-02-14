#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>cnt(n),s(m),d(m);
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		cnt[x-1]++;
	}
	for(auto &x:s)cin>>x;
	for(auto &x:d)cin>>x;
	priority_queue<pair<int,int>>que;
	vector<pair<int,int>>ned;
	for(int i=0;i<n;++i)
		if(cnt[i])que.emplace(cnt[i],i);
	for(int i=0;i<m;++i){
		while(s[i]>=d[i])ned.emplace_back(d[i],i),s[i]-=d[i];
		if(s[i])ned.emplace_back(s[i],i);
	}
	vector<vector<int>> ans(m);
	vector<pair<int,int>>stk;
	for(auto [num,id]:ned){
		for(int i=0;i<num;++i){
			if(que.empty()){
				cout<<"-1\n";
				return ;
			}
			auto [c,x]=que.top();
			que.pop();
			ans[id].push_back(x+1);
			if(--c)stk.emplace_back(c,x);
		}
		while(!stk.empty()){
			que.push(stk.back());
			stk.pop_back();
		}
	}
	for(int i=0;i<m;++i){
		for(auto x:ans[i])cout<<x<<" ";
		cout<<"\n";
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
}
