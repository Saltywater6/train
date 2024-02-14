#include<bits/stdc++.h>
using namespace std;

using ll = long long ;

void solve() {
	ll X;
	cin>>X;
	ll n=1;
	while((1ll<<n)<X)n++;
	n--;
	X-=(1ll<<n);
	vector<int>ans;
	for(ll i=0;i<n;++i)ans.push_back(i+1);
	for(ll i=60;i>=1;--i)if(X>>(i-1)&1)ans.push_back(i);
	cout<<ans.size()<<"\n";
	for(auto x:ans)cout<<x<<" ";
	cout<<"\n";	

}

int main() {
	cin.tie()->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--) solve();
	return  0;
}

