#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;


int main(){
	cin.tie(0)->sync_with_stdio(0);
	//freopen("hayasa","r",stdin);
	int n;
	cin>>n;
	vector<vector<int>>G(n);
	for(int i=1;i<n;++i){
		int a,b;
		cin>>a>>b;
		--a,--b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	auto dfs=[&](auto self,int x,int fa)->pair<int,int>{
		int s1=1e9,s2=0,c=0;
		for(auto y:G[x]){
			if(y==fa)continue;
			auto [fi,se]=self(self,y,x);	
			++c;
			s2+=se;
			s1=min(fi-se,s1);
		}
		if(c==0)return {0,2};
		return	{s2,min(s2+s1+1,s2+2)};
	};
	auto [r1,r2]=dfs(dfs,0,-1);
	cout<<r2<<endl;
}
