#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void solve(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;++i){
		cin>>A[i];	
	}
	cout<<A[0]<<" ";
	ll sum=A[0];
	int c1=A[0]&1;
	for(int i=1;i<n;++i){
		sum+=A[i];
		if(A[i]&1)c1++;
		cout<<sum-(c1/3)-(c1%3==1)<<" ";
	}
	cout<<"\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
