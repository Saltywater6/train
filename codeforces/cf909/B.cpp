#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void solve(){

	int n;
	cin>>n;
	vector<int>A(n);
	for(auto &x:A)cin>>x;
	ll ans=0;
	for(int k=1;k<=n;++k){
		if(n%k)continue;
		ll sum=0;
		vector<ll>vec;
		for(int i=0;i<n;++i){
			sum+=A[i];
			if(i%k==k-1){
				vec.push_back(sum);
				sum=0;
			}
		}
		sort(vec.begin(),vec.end());
		ans=max(ans,vec.back()-vec[0]);
	}
	cout<<ans<<"\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
