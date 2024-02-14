#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;


int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll n;
	cin>>n;
	vector<ll>A(n);
	unordered_map<ll,vector<ll>>B;
	ll sum=0;
	for(ll i=0;i<n;++i){
		cin>>A[i];
		B[A[i]].push_back(i);
	}
//
	for(auto x:A)sum+=x;
	if(sum*2%n==0){
		ll t=sum*2/n;
		vector<ll>ans(n);
		for(ll i=0;i<n;++i){
			ll tmp=t-A[i];
			if(B[tmp].size()){
				ans[i]=B[tmp].back()+1;
				B[tmp].pop_back();
			}else{
				cout<<"-1"<<endl;
				return 0;
			}
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}
	}else cout<<"-1"<<endl;
}
