#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
const int M=2e5+10;
int ls[M*30],rs[M*30],s[M*30],tot,n;
void ins(int &cur,int pre,int v,int L=0,int R=n+1){
	cur=++tot;
	ls[cur]=ls[pre];
	rs[cur]=rs[pre];
	s[cur]=s[pre]+1;
	if(L==R)return ;
	int mid=(L+R)>>1;
	if(v<=mid)ins(ls[cur],ls[pre],v,L,mid);
	else ins(rs[cur],rs[pre],v,mid+1,R);
}
int qry(int cur,int l,int r,int L=0,int R=n+1){
	if(!cur)return 0;
	if(L==l&&r==R)return s[cur];
	int mid=(L+R)>>1;
	if(r<=mid)return qry(ls[cur],l,r,L,mid);
	else if(l>mid)return qry(rs[cur],l,r,mid+1,R);
	return qry(ls[cur],l,mid,L,mid)+
		qry(rs[cur],mid+1,r,mid+1,R);
}
int A[M],rt[2][M];
ll res[M];
multiset<ll>ans;
set<int>st;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)
		ins(rt[0][i],rt[0][i-1],A[i]);
	for(int i=n;i;--i)
		ins(rt[1][i],rt[1][i+1],A[i]);
	for(int i=1;i<=n;++i)
		res[1]+=qry(rt[0][i-1],A[i]+1,n+1);
	ans.insert(res[1]);
	st.insert(0);
	st.insert(n+1);
	ll lst=0;
	for(int q=1;q<=n;++q){
		printf("%lld ",lst=*(--ans.end()));
		ll x;
		scanf("%lld",&x);
		x^=lst;
	 	int r=*st.upper_bound(x)-1;
		int l=*(--st.upper_bound(x))+1;
		st.insert((int)x);
		
		ll ans1=res[l];
		ans1-=qry(rt[0][x-1],A[x]+1,n+1)-qry(rt[0][l-1],A[x]+1,n+1);
		ans1-=qry(rt[1][x+1],0,A[x]-1)-qry(rt[1][r+1],0,A[x]-1);
		ll ans2=0,ans3=0;
		if(x-l<r-x){
			for(int i=l;i<x;++i){
				ans2+=qry(rt[0][i-1],A[i]+1,n+1)-qry(rt[0][l-1],A[i]+1,n+1);
				ans1-=qry(rt[1][x+1],0,A[i]-1)-qry(rt[1][r+1],0,A[i]-1);
			}
			ans3=ans1-ans2;
		}else{
			for(int i=r;i>x;--i){
				ans3+=qry(rt[0][i-1],A[i]+1,n+1)-qry(rt[0][x],A[i]+1,n+1);
				ans1-=qry(rt[0][x-1],A[i]+1,n+1)-qry(rt[0][l-1],A[i]+1,n+1);
			}
			ans2=ans1-ans3;
		}
		ans.erase(ans.find(res[l]));
		if(l!=x){
			res[l]=ans2;
			ans.insert(ans2);
		}else res[x]=0;
		if(r!=x){
			res[x+1]=ans3;
			ans.insert(ans3);
		}else res[x]=0;
	}
	puts("");
	ans.clear();
	st.clear();
	for(int i=1;i<=n;++i)rt[0][i]=rt[1][i]=res[i]=tot=0;
}
int main(){
	//freopen("hayasa","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)solve();
}
