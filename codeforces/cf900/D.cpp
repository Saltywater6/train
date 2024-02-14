#include<bits/stdc++.h>
using namespace std;

void solve(){
	long long n,k,x;
	cin>>n>>k>>x;
	long long l=k*(k+1)/2;
	long long r=(n-k+1+n)*k/2;
	if(l<=x&&x<=r)cout<<"Yes\n";
	else cout<<"No\n";
}


int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
