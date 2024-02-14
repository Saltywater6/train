#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M=1e5+10;
ll A[M],B[M],C[M],D[M],n,m;
bool check(ll op){
	for(ll i=op+1;i<=n;++i)
		if(C[i-op]>=D[i])
			return 0;
	return 1;
}
ll calc(){
	for(ll i=1;i<=n;++i)
		C[i]=A[i],D[i]=B[i];
	sort(C+1,C+n+1);
	sort(D+1,D+n+1);
	ll L=0,R=n,res=0;
	while(L<=R){
		ll mid=(L+R)>>1;
		if(check(mid)){
			R=mid-1,res=mid;
		}else L=mid+1;
	}
	return res;
}
void solve(){
	scanf("%lld%lld",&n,&m);
	for(ll i=2;i<=n;++i)
		scanf("%lld",&A[i]);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&B[i]);
	A[1]=0;
	ll cnt=calc();
	ll L=1,R=m,res=0;
	while(L<=R){
		ll mid=(L+R)>>1;
		A[1]=mid;
		if(calc()==cnt){
			L=mid+1,res=mid;
		}else R=mid-1;
	}
	printf("%lld\n",res*cnt+(m-res)*(cnt+1));
	return ;
}
int main(){
	//freopen("hayasa","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}



