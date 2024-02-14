#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	string s,t;
	cin>>n>>m>>s>>t;
	for(int i=0;i<10;++i){
		if(s.find(t)!=string::npos){
			cout<<i<<"\n";
			return ;
		}
		s+=s;
	}
	cout<<"-1\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
