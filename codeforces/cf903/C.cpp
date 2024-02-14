#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector A(n,vector<int>(n));
	string s;
	for(int i=0;i<n;++i){
		cin>>s;
		for(int j=0;j<n;++j)
			A[i][j]=s[j]-'a';
	}
	int ans=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			int mx=0;
			mx=max(mx,A[i][j]);
			mx=max(mx,A[j][n-i-1]);
			mx=max(mx,A[n-i-1][n-j-1]);
			mx=max(mx,A[n-j-1][i]);
			ans+=mx-A[i][j];
		}
	cout<<ans<<"\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
