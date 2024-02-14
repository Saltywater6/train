#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

void solve(){
	int n;
	cin>>n;
	vector<int>A(n),B(n);
	for(int i=0;i<n;++i)cin>>A[i],A[i]--;;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		x--;
		B[x]=i;
	}
	for(int i=0;i<n;++i)cout<<A[B[i]]+1<<" ";
	cout<<endl;
	for(int i=0;i<n;++i)cout<<i+1<<" ";
	cout<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
