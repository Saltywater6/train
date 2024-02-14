#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;

const ll M=1e5+20;
ll b[M],c[M],x[M];
void solve(){
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;++i){
		cin>>b[i]>>x[i];
		if(b[i]==1)c[i]=c[i-1]+1;
		else if(1e18/(x[i]+1)>=c[i-1])c[i]=c[i-1]*(x[i]+1);
		else c[i]=1e18+1;
	}
	while(q--){
		ll k;
		cin>>k;
		while(1){
			ll l=1,r=n,res;
			while(l<=r){
				ll mid=(l+r)>>1;
				if(c[mid]>=k){
					r=mid-1,res=mid;
				}else l=mid+1;
			}
			if(b[res]==1){
				cout<<x[res]<<" ";
				break;
			}
			//cout<<k<<" "<<c[res]<<endl;
			k=(k-1)%c[res-1]+1;	
		}
	}
	cout<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
