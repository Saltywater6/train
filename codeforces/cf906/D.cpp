#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=2e5+10;
ll A[M],c;
struct node{
	ll a,b;
	bool operator <(const node &_)const{
		return a*c-b<_.a*c-_.b;
	}
}t[M];
void solve(){
	ll n;
	scanf("%lld%lld",&n,&c);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&A[i]),t[i]=(node){i,A[i]};
	sort(t+2,t+n+1);
	ll sum=A[1];
	for(ll i=2;i<=n;++i){
		sum+=t[i].b;
		if(sum<t[i].a*c){
			puts("No");
			return ;
		}
	}
	puts("Yes");
}
int main(){
	ll T;
	scanf("%lld",&T);
	while(T--)solve();
}
