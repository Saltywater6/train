#include<bits/stdc++.h>
using namespace std;

void solve(){
	int a,b;
	cin>>a>>b;
	if(a>b)swap(a,b);
	int g=__gcd(a,b);
	if(g==a)cout<<1ll*b/a*b<<"\n";
	else cout<<1ll*a/g*b<<"\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
