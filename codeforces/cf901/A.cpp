#include<bits/stdc++.h>
using namespace std;

void solve(){
	long long a,b,n;
	cin>>a>>b>>n;
	for(int i=0;i<n;++i){
		long long x;
		cin>>x;
		b+=min(a-1,x);
	}
	cout<<b<<"\n";
		
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
