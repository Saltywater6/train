#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int mx[]={1,1,1,0,-1,-1,-1,0};
int my[]={0,1,-1,1,0,-1,1,-1};
void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	vector mp(n+1,vector<int>(m+1));
	vector dis(n+1,vector<int>(m+1,1e9));
	queue<pair<int,int>>que;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		for(int j=1;j<=m;++j){
			if(s[j-1]=='#')mp[i][j]=1;
			else mp[i][j]=0;
			if(s[j-1]=='v'){
				dis[i][j]=0;
				que.emplace(i,j);
			}
		}
	}
	while(!que.empty()){
		auto [x,y]=que.front();
		que.pop();
		for(int i=0;i<4;++i){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m)continue;
			if(dis[xx][yy]<1e9)continue;
			dis[xx][yy]=dis[x][y]+1;
			que.emplace(xx,yy);
		}
	}
	auto check=[&](int op)->bool{
		vector vis(n+1,vector<int>(m+1,0));
		queue<pair<int,int>>que;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(mp[i][j])que.emplace(i,j),vis[i][j]=1;
		while(!que.empty()){
			auto [x,y]=que.front();
			que.pop();
			for(int i=0;i<8;++i){
				int xx=x+mx[i];
				int yy=y+my[i];
				if(dis[xx][yy]>=op)continue;
				if(vis[xx][yy])continue;
				if(xx==1||yy==1||xx==n||yy==m)
					return 0;
				vis[xx][yy]=1;
				que.emplace(xx,yy);
			}
		}
		return 1;
	};
	int l=0,r=max(n,m),res;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1,res=mid;
		}else  r=mid-1;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<min(res,dis[x][y])<<endl;
	}
}
int main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}
