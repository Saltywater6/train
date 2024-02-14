#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int>A(n),B(n),C(n);
	for(int i=0;i<n;++i)cin>>A[i],C[i]=A[i];
	for(int i=0;i<n;++i)cin>>B[i];	
	ranges::sort(C);
	ranges::sort(B);
	vector<vector<int>>G(2*n+1);
	for(int i=0;i<x;++i){
		if(C[n-x+i]<=B[i]){
			cout<<"No\n";
			return ;
		}
		G[C[n-x+i]].push_back(B[i]);
	}
	for(int i=x;i<n;++i){
		if(C[i-x]>B[i]){
			cout<<"No\n";
			return ;
		}
		G[C[i-x]].push_back(B[i]);
	}

	cout<<"Yes\n";
	for(int i=0;i<n;++i){
		//cout<<G[A[i]].size()<<" ";
		cout<<G[A[i]].back()<<" ";
		G[A[i]].pop_back();
	}
	cout<<"\n";
	return ;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
