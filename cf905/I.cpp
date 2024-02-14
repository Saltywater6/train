#include<bits/stdc++.h>
using namespace std;

using ll=long long ;
const ll M=5e5+10;
ll tag[M<<2],mn[M<<2],n,q,mx[M<<2];
void Down(ll p){
	if(tag[p]){
		tag[p<<1]+=tag[p];
		tag[p<<1|1]+=tag[p];
		mn[p<<1]+=tag[p];
		mn[p<<1|1]+=tag[p];
		mx[p<<1]+=tag[p];
		mx[p<<1|1]+=tag[p];
		tag[p]=0;
	}
}
void Up(ll p){
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}

void upd(ll l,ll r,ll v,ll L=1,ll R=n,ll p=1){
	if(L==l&&r==R){
		mn[p]+=v;
		mx[p]+=v;
		tag[p]+=v;
		return ;
	}
	Down(p);
	ll mid=(L+R)>>1;
	if(r<=mid)upd(l,r,v,L,mid,p<<1);
	else if(l>mid)upd(l,r,v,mid+1,R,p<<1|1);
	else {
		upd(l,mid,v,L,mid,p<<1);
		upd(mid+1,r,v,mid+1,R,p<<1|1);
	}
	Up(p);
}
ll qry(ll L=1,ll R=n,ll p=1){
	if(L==R)return mx[p];
	Down(p);
	ll mid=(L+R)>>1;
	if(mx[p<<1]==0&&mn[p<<1]==0)
		return qry(mid+1,R,p<<1|1);
	return qry(L,mid,p<<1);
}
ll A[M],B[M];
ll l[M],r[M],v[M];
void solve(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&A[i]);
	scanf("%lld",&q);
	ll lst=0;
	for(ll i=1;i<=q;++i){

		scanf("%lld%lld%lld",&l[i],&r[i],&v[i]);
		upd(l[i],r[i],v[i]);
		if(qry()<0){
			for(ll j=lst+1;j<=i;++j)
				upd(l[j],r[j],-v[j]);
			lst=i;	
		}
	}
	for(ll i=lst+1;i<=q;++i)
		upd(l[i],r[i],-v[i]);
	for(ll i=1;i<=lst;++i)
		B[l[i]]+=v[i],B[r[i]+1]-=v[i];		
	for(ll i=1;i<=n;++i){
		B[i]+=B[i-1];
		printf("%lld ",A[i]+B[i]);	
	}
	for(ll i=1;i<=n+1;++i)B[i]=0;
	puts("");
}
int main(){
	//freopen("hayasa","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
