#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int rt[M],ans[M],p[M];
vector<int>G[M];
struct node{
	int l,r,id;
};
vector<node>T[M];
int n,q,tot,s[M<<5],ls[M<<5],rs[M<<5];
int qry(int cur,int l,int r,int L=1,int R=n){
	if(!cur)return 0;
	if(L==l&&r==R)return s[cur];
	int mid=(L+R)>>1;
	if(r<=mid)return qry(ls[cur],l,r,L,mid);
	else if(l>mid)return qry(rs[cur],l,r,mid+1,R);
	return qry(ls[cur],l,mid,L,mid)+qry(rs[cur],mid+1,r,mid+1,R);
}
void upd(int &cur,int x,int L=1,int R=n){
	if(!cur)s[cur=++tot]=0,ls[cur]=rs[cur]=0;
	s[cur]++;
	if(L==R)return ;
	int mid=(L+R)>>1;
	if(x<=mid)upd(ls[cur],x,L,mid);
	else upd(rs[cur],x,mid+1,R);
}
int Merge(int x,int y){
	if(!x||!y)return x|y;
	s[x]+=s[y];
	ls[x]=Merge(ls[x],ls[y]);
	rs[x]=Merge(rs[x],rs[y]);
	return x;
}
void dfs(int x,int f){
	for(int y:G[x]){
		if(y==f)continue;
		dfs(y,x);
		rt[x]=Merge(rt[x],rt[y]);
	}
	upd(rt[x],p[x]);
	//cout<<x<<"-"<<qry(rt[x],p[x],p[x])<<endl; 
	for(auto [l,r,id]:T[x])
		ans[id]=qry(rt[x],l,r);
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<n;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	//cout<<"----"<<endl;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		p[x]=i;
	}
	for(int i=1;i<=q;++i){
		int l,r,x;
		cin>>l>>r>>x;
		T[x].push_back((node){l,r,i});
	}
	dfs(1,0);
	for(int i=1;i<=q;++i)
		if(ans[i])cout<<"Yes\n";
		else cout<<"No\n";
	cout<<"\n";
	for(int i=1;i<=n;++i)G[i].clear(),T[i].clear(),rt[i]=tot=0;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
