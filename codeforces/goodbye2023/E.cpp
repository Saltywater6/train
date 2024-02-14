#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int M=3e5+10;
int n,A[M],tot;
ll ans;
vector<int>G[M];
struct seg{
	int mx[M<<2],tag[M<<2];
	void build(int l=1,int r=n,int p=1){
		mx[p]=tag[p]=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(l,mid,p<<1);
		build(mid+1,r,p<<1|1);
	}
	void Down(int p){
		if(tag[p]){
			tag[p<<1]+=tag[p];
			tag[p<<1|1]+=tag[p];
			mx[p<<1]+=tag[p];
			mx[p<<1|1]+=tag[p];
			tag[p]=0;
		}
	}
	void upd(int l,int r,int v,int L=1,int R=n,int p=1){
		if(L==l&&r==R){
			tag[p]+=v;
			mx[p]+=v;
			return ;
		}
		Down(p);
		int mid=(L+R)>>1;
		if(r<=mid)upd(l,r,v,L,mid,p<<1);
		else if(l>mid)upd(l,r,v,mid+1,R,p<<1|1);
		else {
			upd(l,mid,v,L,mid,p<<1);
			upd(mid+1,r,v,mid+1,R,p<<1|1);
		}
		mx[p]=max(mx[p<<1],mx[p<<1|1]);
	}
	int qry(int l,int r,int L=1,int R=n,int p=1){
		if(l==L&&r==R)return mx[p];
		Down(p);
		int mid=(L+R)>>1;
		if(r<=mid)return qry(l,r,L,mid,p<<1);
		else if(l>mid)return qry(l,r,mid+1,R,p<<1|1);
		return max(qry(l,mid,L,mid,p<<1),qry(mid+1,r,mid+1,R,p<<1|1));
	}
}Tr;
int L[M],R[M];
vector<int>stk[M],T[M];
void dfs(int x,int f){
	L[x]=++tot;
	int mx=1;
    if(!stk[A[x]].empty())
		T[stk[A[x]].back()].push_back(x);
	stk[A[x]].push_back(x);
	for(int y:G[x]){
		if(y==f)continue;
		dfs(y,x);
	}  
	R[x]=tot;
    stk[A[x]].pop_back();
	Tr.upd(L[x],R[x],1);
	for(int y:T[x])
		Tr.upd(L[y],R[y],-1);
	for(int y:G[x]){
		if(y==f)continue;
		int t=Tr.qry(L[y],R[y]);
		ans=max(ans,1ll*mx*t);
		mx=max(t,mx);
	}
	ans=max(ans,1ll*mx);
}
void solve(){
	cin>>n;
	for(int i=2;i<=n;++i){
		int x;
		cin>>x;
		G[x].push_back(i);
	}
	for(int i=1;i<=n;++i)cin>>A[i];
	dfs(1,0);
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i)G[i].clear(),T[i].clear();
	Tr.build(),ans=tot=0;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
