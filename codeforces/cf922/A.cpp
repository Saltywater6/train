#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

void solve(){
	int n,m;
	cin>>n>>m;
	if(m&1)m--;
	cout<<1ll*n*m/2<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
