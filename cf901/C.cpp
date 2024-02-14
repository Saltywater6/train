#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	int g=__gcd(n,m);
	n/=g,m/=g;
	int t=m;
	if(m==1){
		cout<<"0\n";
		return ;
	}
	while(t%2==0)t/=2;
	if(t==1){
		long long ans=0;
		n%=m;
		while(n){
			ans+=n;
			n=n*2;
			n%=m;
		}
		cout<<ans*g<<"\n";

	}else cout<<"-1\n";
}



int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
