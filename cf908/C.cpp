#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>mk(n),A(n);
	vector<vector<int>>G(n);
	for(int &x:A)cin>>x;
	for(int i=0;i<n;++i)if(A[i]<=n)
		G[(n-i-1)%n].push_back(A[i]);
	queue<pair<int,int>>que;
	que.push(pair(0,0));
	mk[0]=1;
	int mx=0;
	while(!que.empty()){
		auto [x,y]=que.front();
		que.pop();
		mx=max(mx,y);
		for(int c:G[x]){
			if(!mk[(x+c)%n]){
				mk[(x+c)%n]=1;
				que.push(pair((x+c)%n,y+1));
			}else {
				cout<<"Yes\n";
				return ;
			}
		}
	}
	cout<<(m>mx?"No\n":"Yes\n");
	return ;
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
