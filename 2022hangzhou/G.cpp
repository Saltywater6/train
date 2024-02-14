#include<bits/stdc++.h>
using namespace std;

using ull=unsigned long long;

const ull mask= chrono::steady_clock::now().time_since_epoch().count();
ull shift(ull x){
	x^=mask;
	x^=x<<13;
	x^=x>>7;
	x^=x<<17;
	x^=mask;
	return x;
}

const int M=1e6+01;
vector<int>G[M];
int ind[M];
ull cir[M];

ull dfs(int x,int f){
	ull h=1;
	for(auto y:G[x]){
		if(y==f)continue;
		if(ind[y]>=2)continue;
		h+=shift(dfs(y,x));
	}
	return h;
}
bool mk[M];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		ind[a]++,ind[b]++;
	}
	if(m<n)cout<<"YES\n";
	if(m>n)cout<<"NO\n";
	if(m==n){
		queue<int>que;
		for(int i=1;i<=n;++i)if(ind[i]==1)que.push(i);
		while(!que.empty()){
			int x=que.front();
			que.pop();
			for(auto y:G[x]){
				if(--ind[y]==1)que.push(y);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;++i)if(ind[i]>=2){
			queue<int>que;
			que.push(i);
			while(!que.empty()){
				int x=que.front();
				que.pop();
				mk[x]=1;
				cir[++cnt]=dfs(x,0);
				//cout<<x<<" "<<cir[cnt]<<endl;
				for(auto y:G[x]){
					if(!mk[y]&&ind[y]>=2){
						que.push(y);
						break;
					}
				}
			}
			break;
		}
		bool ans=1;
		for(int i=2;i<=cnt;++i)
			if(cir[i]!=cir[i-1])
				ans=0;
		if(ans==0&&cnt%2==0){
			ans=1;
			for(int i=3;i<=cnt;++i)
				if(cir[i]!=cir[i-2])
					ans=0;
		}
		cout<<(ans?"YES":"NO")<<"\n";
	}
	for(int i=1;i<=n;++i)G[i].clear(),ind[i]=mk[i]=0;
}

int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();

}
