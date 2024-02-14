#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

void solve(){
	ll a,b,r;
	cin>>a>>b>>r;
	auto calc=[&](ll a,ll b,ll r)->ll{
		int fl=0;
		ll ans=0;
		ll t=0;
		for(int i=60;i>=0;--i){
			int ba=a>>i&1,bb=b>>i&1;
			if(ba==1&&bb==0){
				if(fl==0){
					fl=1,ans+=1ll<<i;
				}else {
					if(t+(1ll<<i)<=r){
						t+=1ll<<i;
						ans-=1ll<<i;
					}else ans+=1ll<<i;
				}
			}
			if(ba==0&&bb==1){
				if(fl==0){
					if(t+(1ll<<i)<=r){
						t+=1ll<<i;
						ans+=1ll<<i;
						fl=1;
					}else return 1e18;
				}else ans-=1ll<<i;
			}
		}
		return ans;
	};
	cout<<min(calc(a,b,r),calc(b,a,r))<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
