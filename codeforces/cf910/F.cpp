#include<bits/stdc++.h>
using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void solve(){
	int n,m;
	cin>>n>>m;
	vector A(n,vector<int>(m));
	vector dis(n,vector<int>(m,-1));
	int stx,sty,sum=0;
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		for(int j=0;j<m;++j){
			A[i][j]=s[j]=='#';
			sum+=1-A[i][j];	
			if(s[j]=='V')stx=i,sty=j;
		}
	}
	sum-=1;
	dis[stx][sty]=0;
	queue<pair<int,int>>que;
	que.emplace(stx,sty);
	while(!que.empty()){
		auto [x,y]=que.front();
		que.pop();
		for(int i=0;i<4;++i){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0||xx>=n||yy<0||yy>=m)continue;
			if(dis[xx][yy]!=-1)continue;
			if(A[xx][yy])continue;
			dis[xx][yy]=dis[x][y]+1;
			que.emplace(xx,yy);
		}
	}
	int cnt=0,ans=0;
	for(int i=0;i<n;++i){
		if(dis[i][0]!=-1)cnt++,ans=dis[i][0];
		if(dis[i][m-1]!=-1)cnt++,ans=dis[i][m-1];
	}
	for(int i=1;i<m-1;++i){
		if(dis[0][i]!=-1)cnt++,ans=dis[0][i];
		if(dis[n-1][i]!=-1)cnt++,ans=dis[n-1][i];
	}
	if(cnt==0)cout<<sum<<"\n";
	if(cnt==1)cout<<sum-ans<<"\n";
	if(cnt>=2){
		struct node{
			int a,b,c,d;
		};
		queue<node>que;
		vector d1(n,vector<int>(m,-1));
		vector d2(n,vector<int>(m,-1));
		vector b1(n,vector<int>(m,-1));
		vector b2(n,vector<int>(m,-1));
		int cnt=0;
		auto upd= [&](auto &d,auto &b,int x,int y,int D,int id)->void{
			d[x][y]=D,b[x][y]=id;
			que.emplace(x,y,D,id);
		};

		for(int i=0;i<n;++i){
			if(dis[i][0]!=-1)upd(d1,b1,i,0,0,cnt++);
			if(dis[i][m-1]!=-1)upd(d1,b1,i,m-1,0,cnt++);
		}
		for(int i=1;i<m-1;++i){
			if(dis[0][i]!=-1)upd(d1,b1,0,i,0,cnt++);
			if(dis[n-1][i]!=-1)upd(d1,b1,n-1,i,0,cnt++);
		}
		while(!que.empty()){
			auto [x,y,d,id]=que.front();
			que.pop(),++d;
			for(int i=0;i<4;++i){
				int xx=x+dx[i],yy=y+dy[i];
				if(xx<0||yy<0||xx>=n||yy>=m)continue;
				if(A[xx][yy])continue;
				if(b1[xx][yy]==id||b2[xx][yy]==id)continue;
				if(d2[xx][yy]==-1||d2[xx][yy]>d)
					upd(d2,b2,xx,yy,d,id);
				if(d2[xx][yy]<d1[xx][yy]||d1[xx][yy]==-1)
					swap(d2[xx][yy],d1[xx][yy]),swap(b2[xx][yy],b1[xx][yy]);
			}
		}
		int ans=-1;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if(d1[i][j]==-1||d2[i][j]==-1||dis[i][j]==-1)continue;
				int t=d1[i][j]+d2[i][j]+dis[i][j];
				if(ans==-1||ans>t)ans=t;
			}
		cout<<sum-ans<<"\n";
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
