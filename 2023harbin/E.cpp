#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int M=1e5+10;
int ans[M],A[M],B[M],C[M],w[M];
vector<int>neg,pos;
int n;
ll sa[M],sb[M],D[M];
bool check(ll op){
	for(int i=1;i<=n;++i)
		D[i]=op/C[i]-sb[1]-B[i];
	sort(neg.begin(),neg.end(),[&](int i,int j){return D[i]-w[i]>D[j]-w[j];});

	sort(pos.begin(),pos.end(),[&](int i,int j){return D[i]<D[j];});
	ll sum=0;
	for(int x:neg){
		sum+=w[x];
		if(sum>D[x])return 0;
	}
	for(int x:pos){
		sum+=w[x];
		if(sum>D[x])return 0;
	}
	int cnt=0;
	for(int x:neg)ans[++cnt]=x;
	for(int x:pos)ans[++cnt]=x;
	return 1;
}

void solve(){
	scanf("%d",&n);
	pos.clear(),neg.clear();
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&A[i],&B[i],&C[i]);
		w[i]=A[i]-B[i];
		if(w[i]>=0)pos.push_back(i);
		else neg.push_back(i);
	}
	for(int i=1;i<=n;++i)sa[i]=sa[i-1]+A[i];
	sb[n+1]=0;
	for(int i=n;i>=1;--i)sb[i]=sb[i+1]+B[i];
	ll L=0,R=1e18,res=0;
	while(L<=R){
		ll mid=(L+R)>>1;
		if(check(mid))R=mid-1,res=mid;
		else L=mid+1;
	}
	for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);

}
	
int main(){
	int T;
	cin>>T;
	while(T--)solve();
}
