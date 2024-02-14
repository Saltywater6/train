#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int ans=0;
	vector<int>c(n);
	c[n-1]=s.back()=='B';
	for(int i=n-2;i>=0;--i)
		c[i]=c[i+1]|(s[i]=='B');
	bool fl=0;
	for(int i=0;i<n-1;++i){
		if(s[i]=='A')fl=1;
		ans+=fl&&c[i+1];
		//cout<<fl<<" "<<c[i+1]<<"\n";
	}
	cout<<ans<<"\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
