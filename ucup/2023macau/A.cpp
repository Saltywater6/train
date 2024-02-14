#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	vector A(n,vector<int>(n));
	vector ans(n,vector<int>(n));
	vector<int> r(n),c(n);
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		for(int j=0;j<n;++j){
			if(s[j]=='+')A[i][j]=1;
			else A[i][j]=-1;
		}
	}
	for(int i=0;i<n;++i)cin>>r[i];
	for(int i=0;i<n;++i)cin>>c[i];
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(A[i][j]==-1)
				r[i]++,c[j]++;
	for(int j=0;j<n;++j){
		priority_queue<pair<int,int>>que;
		for(int i=0;i<n;++i)
			que.emplace(r[i],i);
		while(c[j]&&!que.empty()){
			auto [_,i]=que.top();
			que.pop();
			if(c[j]&&r[i])
				c[j]--,r[i]--,ans[i][j]=1;
		}
		
		//if(c[j])cout<<j<<endl;
		if(c[j]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;	
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(A[i][j]==1)cout<<ans[i][j];
			else cout<<1-ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
