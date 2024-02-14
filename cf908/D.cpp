#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>A(n),B(m);
	for(int &x:A)cin>>x;
	for(int &x:B)cin>>x;
	sort(B.begin(),B.end(),greater<int>());
	int p=0;
	while(p<m&&B[p]>=A[0])cout<<B[p++]<<" ";
	for(int i=0;i<n-1;++i){
		cout<<A[i]<<" ";
		if(A[i]>A[i+1])
			while(p<m&&B[p]>=A[i+1])
				cout<<B[p++]<<" ";
	}
	cout<<A[n-1]<<" ";
	while(p<m)cout<<B[p++]<<" ";
	cout<<"\n";
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
