#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
void solve(){
	int n,m;
	cin>>n>>m;
	vector A(n,vector<int>(m));
	vector<int>vis(n),tag(n);
	vector<vector<int>>vec(m);
	vector<vector<pair<int,int>>> G(n);
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		for(int j=0;j<m;++j){
			if(s[j]=='1')vec[j].push_back(i);
		}
	}
	for(int j=0;j<m;++j){
		if(vec[j].size()+vec[m-j-1].size()>2){
			cout<<0<<endl;
			return ;
		}
		if(vec[j].size()==2){
			G[vec[j][0]].emplace_back(vec[j][1],1);
			G[vec[j][1]].emplace_back(vec[j][0],1);
		}
		if(vec[j].size()==1&&vec[m-j-1].size()==1)
			G[vec[j][0]].emplace_back(vec[m-j-1][0],0);
	}
	int flag=0,ans=1;
	auto dfs=[&](auto self ,int x)->void{
		vis[x]=1;
		for(auto [y,val]:G[x]){
			if(vis[y]){
			//cout<<x<<" "<<y<<"-"<<val<<endl;
				if(tag[y]!=(tag[x]^val)){
					flag=1;
					return ;
				}
			}else {
				tag[y]=tag[x]^val;
				self (self,y);
			}
		}
	};
	for(int i=0;i<n;++i)if(!vis[i]){
		flag=0,dfs(dfs,i);
		if(flag){
			cout<<0<<endl;
			return ;
		}
		ans=ans*2%mod;
	}
	cout<<ans<<endl;
}

int main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
}
