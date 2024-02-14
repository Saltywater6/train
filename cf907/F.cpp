#include<bits/stdc++.h>
using namespace std;

using ll=long long ;
const ll M=5e5+10;
struct BIT{
	ll f[M];
	void upd(ll x,ll v){
		x++;
		while(x)f[x]+=v,x-=x&-x;
	}
	ll qry(ll x){
		ll res=0;
		x++;
		while(x<M)res+=f[x],x+=x&-x;
		return res;
	}
}Tr;
struct node{
	ll v,t;
};
vector<node>T[M];
vector<int>G[M];
ll ans[M],ti[M];;
void dfs(ll x){
	for(auto t:T[x])
		Tr.upd(t.t,t.v);
	ans[x]=Tr.qry(ti[x]);
	for(ll y:G[x])dfs(y);
	for(auto t:T[x])
		Tr.upd(t.t,-t.v);
}
void solve(){
	ll q;
	scanf("%lld",&q);
	ll sz=1;
	for(ll i=1;i<=q;++i){
		ll op;
		scanf("%lld",&op);
		if(op==1){
			ll x;
			scanf("%lld",&x);
			ti[++sz]=i;
			G[x].push_back(sz);
		}else {
			ll v,a;
			scanf("%lld%lld",&a,&v);
			T[a].push_back((node){v,i});
		}
	}
	dfs(1);
	for(ll i=1;i<=sz;++i)printf("%lld ",ans[i]);
	puts("");
	for(ll i=1;i<=sz;++i)G[i].clear(),T[i].clear();
}
int main(){
	//freopen("hayasa","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
