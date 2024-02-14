#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

const int M=2e5+10;
int dep[M],L[M],R[M];
int n,k;
vector<int>G[M];
priority_queue<int>que;
struct Seg{
	int s[M<<2];
	int Up(int a,int b){
		return dep[a]<dep[b]?b:a;
	}
	void upd(int x,int v,int l,int r,int p){
		if(l==r){
			s[p]=v;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)upd(x,v,l,mid,p<<1);
		else upd(x,v,mid+1,r,p<<1|1);
		s[p]=Up(s[p<<1],s[p<<1|1]);
	}
	int qry(int l,int r,int L,int R,int p){
		if(L==l&&r==R)return s[p];
		int mid=(L+R)>>1;
		if(r<=mid)return qry(l,r,L,mid,p<<1);
		else if(l>mid)return qry(l,r,mid+1,R,p<<1|1);
		return Up(qry(l,mid,L,mid,p<<1),
				qry(mid+1,r,mid+1,R,p<<1|1));
	}
}Tr;
void dfs(int x,int f){
	static int tot;
	dep[x]=dep[f]+1;
	L[x]=++tot;
	if(G[x].size()==0)
		Tr.upd(L[x],x,1,n,1);
	for(auto y:G[x])dfs(y,x);	
	R[x]=tot;
}
void redfs(int x){
	for(auto y:G[x]){
		int t=Tr.qry(L[y],R[y],1,n,1);
		Tr.upd(L[t],0,1,n,1);
		que.push(dep[t]-2*dep[x]);
		redfs(y);
	}
}
void solve(){

	cin>>n>>k;
	for(int i=2;i<=n;++i){
		int x;
		cin>>x;
		G[x].emplace_back(i);
	}
	dfs(1,0);
	redfs(1);
	//for(int i=1;i<=n;++i)cout<<L[i]<<" "<<R[i]<<endl;
	int ans=2*(n-1);
	k++;
	while(k--&&!que.empty()&&que.top()>0)
		ans-=que.top(),que.pop();
	cout<<ans<<endl;

}
int main(){
	//cin.tie(0)->sync_with_stdio(0);
	dep[0]=-1;
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}
