#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		cout<<1000000000-n+i<<" ";
	cout<<"\n";
}


int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
