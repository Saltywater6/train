#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

void solve(){
	int n,k,x;
	cin>>n>>k>>x;
	vector<int>A(n);
	for(int i=0;i<n;++i)cin>>A[i];
	sort(A.begin(),A.end());
	A.insert(A.begin(),0);
	for(int i=1;i<=n;++i)A[i]+=A[i-1];
	int ans=-1e9;
	for(int i=0;i<=k;++i){
		ans=max(ans,-A[n-i]+2*A[max(0,n-i-x)]);
	}
	cout<<ans<<endl;

}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0 ;
}
