#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;++i)
		if(s[i]!='1'){
			cout<<"YES\n";
			return ;
		}
	cout<<"NO\n";
	return ;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;

	while(T--)solve();
}
	
