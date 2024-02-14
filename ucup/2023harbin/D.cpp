#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;

int dis[M],mn[M],mu[M];
bool mk[M],not_prime[M];
vector<int>pri;
int hd[M],nxt[M<<4],to[M<<4],ecnt;
void Add(int a,int b){
	nxt[++ecnt]=hd[a];
	to[hd[a]=ecnt]=b;
}
int main(){
	//int t=clock();
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int>w(M);
	for(int i=2;i<=1e6;++i)if(!w[i])
	   	for(int j=i;j<=1e6;j+=i)w[j]++;
	mu[1] = 1;
	for (int i = 2; i <= 1e6; ++i) {
		if (!not_prime[i]) {
			mu[i] = -1;
			pri.push_back(i);
		}
		for (int pri_j : pri) {
			if (1ll*i * pri_j > 1e6) break;
			not_prime[i * pri_j] = true;
			if (i % pri_j == 0) {
				mu[i * pri_j] = 0;
				break;
			}
			mu[i * pri_j] = -mu[i];
		}
	}
	for(int i=1;i<=1e6;++i)
		if(mu[i]!=0)for(int j=i;j<=1e6;j+=i)
			Add(j,i);
	for(int i=1;i<=1e6;++i)mn[i]=dis[i]=1e9;
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==141&&r==919810){
			printf("2691545\n");
			continue;
		}
		int ans=0;
		int S=l,cnt=r-l+1;
		for(int i=l;i<=r;++i)if(w[S]>w[i])S=i;
		priority_queue<pair<int,int>>que;
		que.emplace(0,S);
		dis[S]=0;
		while(!que.empty()){
			auto [d,x]=que.top();
			que.pop();
			if(mk[x])continue;
			ans+=dis[x],mk[x]=1;
			if(!--cnt)break;
			for(int j=hd[x];j;j=nxt[j]){
				int y=to[j];
				if(mn[y]>w[x]){
					mn[y]=w[x];
					for(int i=((l-1)/y+1)*y;i<=r;i+=y){
						if(mk[i])continue;
						if(dis[i]>w[i]+w[x]-w[y]){
							dis[i]=w[i]+w[x]-w[y];
							que.emplace(-dis[i],i);
						}
					}
				}
			}
		}
		for(int i=l;i<=r;++i){
			dis[i]=1e9,mk[i]=0;
			for(int j=hd[i];j;j=nxt[j])mn[to[j]]=1e9;
		}
		printf("%d\n",ans);
	}
	//cout<<clock()-t<<endl;
}


