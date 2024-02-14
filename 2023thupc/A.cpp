#include<bits/stdc++.h>
using namespace std;

using ll=long long ;
bool f1;
const int M=4e5+10;
int nxt[M<<1],hd[M],to[M<<1],ecnt,val[M<<1];
ll dis[M];
bool f[M][20][20],mk[M];
bool f2;
void Add(int a,int b,int c){
	nxt[++ecnt]=hd[a];
	to[hd[a]=ecnt]=b;
	val[ecnt]=c;
}
int main(){
//	cerr<<(&f2-&f1)/1024.0/1024<<endl;
	//freopen("hayasa","r",stdin);
	cin.tie(0)->sync_with_stdio(0);
	int k,m,s;
	cin>>k>>m>>s;
	int n=(1<<k)-1;
	vector<int>A(k+1);
	for(int i=1;i<=k;++i)cin>>A[i];
	for(int i=0;i<m;++i){
		int x,y,c;
		cin>>x>>y>>c;
		Add(x,y,c);
		Add(y,x,c);
	}
	memset(dis,63,sizeof dis);
	priority_queue<pair<ll ,int>>que;
	dis[s]=0;
	que.emplace(-dis[s],s);
	while(!que.empty()){
		auto [d,x]=que.top();
		que.pop();
		if(mk[x])continue;
		mk[x]=1;
		queue<tuple<int,int,int>>q;
		q.emplace(x,0,0);
		f[x][0][0]=1;
		int t=x;
		while(!q.empty()){
			auto [x,a,b]=q.front();
			q.pop();
			if(dis[x]>dis[t]+A[b]){
				dis[x]=dis[t]+A[b];
				que.emplace(-dis[x],x);
			}
			if(a<k){
				if(f[x][a+1][b]==0){
					f[x][a+1][b]=1;
					q.emplace(x,a+1,b);
				}
				if(f[x^(1<<a)][a+1][b+1]==0){
					f[x^(1<<a)][a+1][b+1]=1;
					q.emplace(x^(1<<a),a+1,b+1);
				}
			}
		}
		for(int i=hd[x];i;i=nxt[i]){
			int y=to[i];
			if(dis[y]>dis[x]+val[i]){
				dis[y]=dis[x]+val[i];
				que.emplace(-dis[y],y);
			}
		}
	}
	for(int i=0;i<=n;++i)cout<<dis[i]<<" ";
	cout<<"\n";
}
	


