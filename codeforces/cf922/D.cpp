#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

const ll M=1e5+10;
ll A[M],f[M],s[M];
ll que[M];
void solve(){
	ll n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>A[i];
		s[i]=s[i-1]+A[i];
	}
	A[n+1]=0;
	auto check=[&](ll op)->bool{
		memset(f,0,sizeof(ll)*(n+2));
		int l=1,r=0;
		que[++r]=0;
		for(ll i=1;i<=n+1;++i){
			while(l<=r&&s[i-1]-s[que[l]]>op)l++;
			f[i]=f[que[l]]+A[i];
			while(l<=r&&f[i]<=f[que[r]])r--;
			que[++r]=i;
		}
		//for(int i=1;i<=n+1;++i)cout<<f[i]<<" ";
		return f[n+1]<=op;
	};
	ll l=0,r=1e17,res=0;
	//check(11);
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1,res=mid;
		}else l=mid+1;
	}
	cout<<res<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
