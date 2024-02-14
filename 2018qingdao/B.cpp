#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int M=4e5+10;
bool vio;
int L[M],R[M],tot;
ll dis[M],cost[M];
bool mk[M];
int hd[M],nxt[M],to[M],val[M],ecnt;
int fa[18][M],v[M],dep[M];
bool let;
char IO;
int rd(){
	int res=0;
	while(IO=getchar(),IO<48||IO>57);
	do res=(res<<1)+(res<<3)+(IO^48);
	while(IO=getchar(),isdigit(IO));
	return res;
}
void dfs(int x,int f){
	L[x]=++tot;
	fa[0][x]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=17;++i)
		fa[i][x]=fa[i-1][fa[i-1][x]];
	if(mk[x])cost[x]=0;
	for(int i=hd[x];i;i=nxt[i]){
		int y=to[i];
		if(y==f)continue;
		cost[y]=cost[x]+val[i];
		dis[y]=dis[x]+val[i];
		dfs(y,x);
	}
	R[x]=tot;
}
void Add(int a,int b,int c){
	nxt[++ecnt]=hd[a];
	to[hd[a]=ecnt]=b;
	val[ecnt]=c;
}
int k;
int LCA(int a,int b){
	if(dep[a]>dep[b])swap(a,b);
	int stp=dep[b]-dep[a];
	for(int i=17;i>=0;--i)
		if(stp>>i&1)b=fa[i][b];
	if(a==b)return a;
	for(int i=17;i>=0;--i)
		if(fa[i][a]!=fa[i][b])
			a=fa[i][a],b=fa[i][b];
	return fa[0][a];
}
bool check(ll op){
	int fir=0,lst=0;
	for(int i=1;i<=k;++i)
		if(cost[v[i]]>op){
			if(!fir)fir=v[i];
			lst=v[i];
		}
	if(!fir||fir==lst)return 1;
	int t=LCA(fir,lst);
	for(int i=1;i<=k;++i)if(cost[v[i]]>op)
		if(dis[v[i]]-dis[t]>op)return 0;
	return 1;
}
bool cmp(int a,int b){
	return L[a]<L[b];
} 
void solve(){
	int n=rd(),m=rd(),q=rd();
	for(int i=1;i<=m;++i)mk[rd()]=1;
	for(int i=2;i<=n;++i){
		int a=rd(),b=rd(),c=rd();
		Add(a,b,c),Add(b,a,c);
	}
	dfs(1,0);
	while(q--){
		k=rd();
		for(int i=1;i<=k;++i)v[i]=rd();
		sort(v+1,v+k+1,cmp);
		ll L=0,R=1e14,res=0;
		while(L<=R){
			ll mid=(L+R)>>1;
			if(check(mid)){
				R=mid-1,res=mid;
			}else L=mid+1;
		}
		printf("%lld\n",res);
	}
	for(int i=1;i<=n;++i)hd[i]=mk[i]=ecnt=0;
}
int main(){
	//freopen("hayasa","r",stdin);
	int T=rd();
	while(T--)solve();
	return 0;
}
