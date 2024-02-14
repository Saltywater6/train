#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;++i)cin>>A[i];
	cout<<(A[0]==1?"Yes":"No")<<"\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
