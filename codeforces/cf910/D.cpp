#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int>A(n),B(n);
	for(int i=0;i<n;++i)cin>>A[i];
	for(int i=0;i<n;++i)cin>>B[i];
	int mn=max(A[0],B[0]);
	for(int i=0;i<n;++i)mn=min(mn,max(A[i],B[i]));
	long long ans=0;
	for(int i=0;i<n;++i)ans+=abs(A[i]-B[i]);
	long long res=ans;
	for(int i=0;i<n;++i){
		int t=min(A[i],B[i]);
		res=max(res,ans+(t-mn)*2);
	}
	cout<<res<<"\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
