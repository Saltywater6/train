#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

bool f1;
const ll M=2e5+10;
ll s1[M][305],s2[M][305],A[M];
void solve(){
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;++i)cin>>A[i];
	for(ll k=1;k<=300;++k)
		for(ll i=n;i>=1;--i){
			s2[i][k]=s1[i][k]=0;
			if(i+k<=n){
				s2[i][k]=s2[i+k][k];
				s1[i][k]=s1[i+k][k];
			}
			s2[i][k]+=A[i];
			s1[i][k]+=s2[i][k];
		}
	//cout<<s1[1][1]<<"----"<<endl;
	while(q--){
		ll s,d,k;
		cin>>s>>d>>k;
		if(k<=700){
			ll ans=0;
			for(ll i=1;i<=k;++i)
				ans+=1ll*A[(i-1)*d+s]*i;
			cout<<ans<<' ';
		}else{
			cout<<s1[s][d]-s1[s+d*k][d]-k*s2[s+d*k][d]<<' ';
		}
	}
	cout<<endl;

}
bool f2;

int main(){
	cerr<<(&f2-&f1)/1024.0/1024<<endl;
	cin.tie(0)->sync_with_stdio(0);
	ll T=1;
	cin>>T;
	while(T--)solve();
}
