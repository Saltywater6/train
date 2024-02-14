#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int top=0;
	for(int i=0;i<n;++i){
		if(s[i]=='-')top--;
		else top++;
	}
	cout<<abs(top)<<"\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
}
