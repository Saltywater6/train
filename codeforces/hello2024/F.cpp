#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

const ll M=5e5+10;
ll A[M],B[M],C[M];
struct Seg{
	struct mat{
		ll A[2][2];
		mat(){
			A[0][0]=A[0][1]=A[1][0]=A[1][1]=1e18;
		}
		ll val(){
			return min(min(A[0][0],A[0][1]),min(A[1][0],A[1][1]));
		}
	}s[M<<2];
	void Up(int p,int L,int R){
		int mid=(L+R)>>1;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j){
				s[p].A[i][j]=min({s[p<<1].A[i][0]+s[p<<1|1].A[0][j],
						s[p<<1].A[i][0]+s[p<<1|1].A[1][j],
						s[p<<1].A[i][1]+s[p<<1|1].A[1][j],
						s[p<<1].A[i][1]+s[p<<1|1].A[0][j]+C[mid]});
			}
	}
	void build(ll L,ll R,ll p){
		if(L==R){
			s[p].A[0][0]=A[L];
			s[p].A[1][1]=B[L];
			return ;
		}
		ll mid=(L+R)>>1;
		build(L,mid,p<<1);
		build(mid+1,R,p<<1|1);
		Up(p,L,R);
	}
	void upd(ll x,ll a,ll b,ll c,ll L,ll R,ll p){
		if(L==R){
			s[p].A[0][0]=a;
			s[p].A[1][1]=b;
			return ;
		}
		ll mid=(L+R)>>1;
		if(x<=mid)upd(x,a,b,c,L,mid,p<<1);
		else upd(x,a,b,c,mid+1,R,p<<1|1);
		Up(p,L,R);
	}
}Tr;
void solve(){
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;++i)cin>>A[i];
	for(ll i=1;i<=n;++i)cin>>B[i];
	for(ll i=1;i<n;++i)cin>>C[i];
	Tr.build(1,n,1);
	while(q--){
		ll p,x,y,z;
		cin>>p>>x>>y>>z;
		A[p]=x,B[p]=y,C[p]=z;
		Tr.upd(p,x,y,z,1,n,1);
		cout<<Tr.s[1].val()<<endl;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}

