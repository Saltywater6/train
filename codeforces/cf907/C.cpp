#include<bits/stdc++.h>
using namespace std;

using ll= long long;
const ll M=2e5+10;
ll A[M];
void solve(){
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&A[i]);
	sort(A+1,A+n+1);
	ll comb=0,R=n,ans=0;
	for(ll i=1;i<=n;++i){
		if(i==R){
			if((comb+A[i])%2==0){
				ans+=(A[i]-comb)/2+1;
			}else{
				ans+=min(A[i],(A[i]-comb)/2+2);
			}
			break;
		}else{
			if(comb+A[i]>A[R]){
				if(R!=i+1){
					comb=comb+A[i]-A[R];
					ans+=A[i]+1;
					R--;
				}else{
					ans+=A[R]-comb+1;
					A[i]-=A[R]-comb;
					comb=0;
					if(A[i]&1){
						ans+=min(A[i],A[i]/2+2);
					}else ans+=A[i]/2+1;
					break;
				}
			}else{
				ans+=A[i],comb+=A[i];
			}
		}
		//cout<<i<<" "<<comb<<" "<<ans<<" "<<R<<endl;
	}
	printf("%lld\n",ans);
}
int main(){
	//freopen("hayasa","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
