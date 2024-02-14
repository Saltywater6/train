#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	for(char i='1';i<='8';++i)
		if(i!=s[1])cout<<s[0]<<i<<endl;
	for(char i='a';i<='h';++i)
		if(i!=s[0])cout<<i<<s[1]<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
}

