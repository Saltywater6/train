#include<bits/stdc++.h>
using namespace std;

using ll=long long ;
using pii = pair<ll ,ll >;
const ll P=1e9+7;
void solve(){
	ll n;
	cin>>n;
	vector<ll>A(n);
	vector<ll>ans1(n),ans2(n);
	for(ll i=0;i<n;++i)cin>>A[i];
	ll x=max_element(A.begin(),A.end())-A.begin();
	vector<pii>stk;
	ll sum0=0,sum1=0,res1=0,res2=0;
	for(ll i=1;i<n;++i){
		ll d=(A[(x+i-1)%n]-A[(x+i)%n]);
		if(d>0){
			stk.emplace_back(i,d);
			sum0+=d;
			res2+=d;
		}else{
			d=-d;
			while(d>0){
				auto &[x,y]=stk.back();
				ll t=min(y,d);
				y-=t,d-=t;
				sum1+=P-t*(i-x)%P;
				sum1%=P;
				sum0-=t;
				if(y==0)stk.pop_back();
			}
		}
		res1+=2*sum1+sum0;
		res1%=P;
		sum1+=sum0;
		sum1%=P;
		ans1[(x+i+1)%n]+=res1;
		ans1[(x+i+1)%n]%=P;
		ans2[(x+i+1)%n]+=res2;
	}
	stk.clear();
	sum1=sum0=res1=res2=0;
	for(ll i=1;i<n;++i){
		ll d=(A[(x-i+n+1)%n]-A[(x-i+n)%n]);
		if(d>0){
			stk.emplace_back(i,d);
			sum0+=d;
			res2+=d;
		}else{
			d=-d;
			while(d>0){
				auto &[x,y]=stk.back();
				ll t=min(y,d);
				y-=t,d-=t;
				sum1+=P-t*(i-x)%P;
				sum1%=P;
				sum0-=t;
				if(y==0)stk.pop_back();
			}
		}
		res1+=2*sum1+sum0;
		res1%=P;
		sum1+=sum0;
		sum1%=P;
		ans1[(x-i+n)%n]+=res1;
		ans1[(x-i+n)%n]%=P;
		ans2[(x-i+n)%n]+=res2;
	}
	for(ll i=0;i<n;++i)
		printf("%lld %lld\n",ans2[i],ans1[i]);
}
int main(){
	//freopen("hayasa","r",stdin);
	ll T;
	scanf("%d",&T);
	while(T--)solve();
}
