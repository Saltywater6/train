#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,ans=1e9;
	cin>>n;
	vector<int>A(n),f(n,1e9),g(n,1e9);
	for(int i=0;i<n;++i)cin>>A[i];
	for(int i=n-1;i>=0;--i){
		if(i+A[i]<n)f[i]=n-1-A[i];
		if(i+A[i]<n-1&&g[i+A[i]+1]!=-1){
			f[i]=min(f[i],g[i+A[i]+1]-A[i]-1);
		}
		if(i<n-1)g[i]=min(f[i],g[i+1]);
		ans=min(ans,f[i]);
	}
	cout<<(ans==1e9?n:ans)<<"\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}

