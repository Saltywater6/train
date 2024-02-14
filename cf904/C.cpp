#include<bits/stdc++.h>
using namespace std;

int n,m;
const int M=5e5+10;
struct Seg{
	int mx[M<<2],mn[M<<2],tag[M<<2];
	void Down(int p){
		if(tag[p]){
			mx[p<<1]+=tag[p];
			mn[p<<1]+=tag[p];
			mx[p<<1|1]+=tag[p];
			mn[p<<1|1]+=tag[p];
			tag[p<<1]+=tag[p];
			tag[p<<1|1]+=tag[p];
			tag[p]=0;
		}
	}
	void upd(int l,int r,int v,int L=0,int R=m,int p=1){
		if(L==l&&r==R){
			mx[p]+=v,mn[p]+=v,tag[p]+=v;
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
		mn[p]=min(mn[p<<1],mn[p<<1|1]);
	}
	void clear(int L=0,int R=m,int p=1){
		mx[p]=mn[p]=tag[p]=0;
		if(L==R)return ;
		int mid=(L+R)>>1;
		clear(L,mid,p<<1);
		clear(mid+1,R,p<<1|1);
	}
}Tr;
void solve(){
	cin>>n>>m;
	vector<pair<int,int>>Q(n);
	vector<int>T;
	T.emplace_back(1);
	T.emplace_back(m);
	for(auto &[l,r]:Q){
		cin>>l>>r;
		T.emplace_back(l);
		T.emplace_back(r);
	}	
	sort(T.begin(),T.end());
	m=lower_bound(T.begin(),T.end(),m)-T.begin();
	vector<vector<int>>G(m+1),E(m+1);
	for(auto &[l,r]:Q){
		l=lower_bound(T.begin(),T.end(),l)-T.begin();
		r=lower_bound(T.begin(),T.end(),r)-T.begin();
		//cout<<m<<" "<<l<<" "<<r<<endl;
		G[l].push_back(r);
		E[r].push_back(l);
	}
	int ans=0;
	for(int i=0;i<=m;++i){
		for(auto x:G[i])Tr.upd(i,x,1);
		ans=max(ans,Tr.mx[1]-Tr.mn[1]);
		for(auto x:E[i])Tr.upd(x,i,-1);
	}
	Tr.clear();
	cout<<ans<<"\n";
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
