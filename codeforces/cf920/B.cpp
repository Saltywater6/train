#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	int c1=0,c2=0;
	for(int i=0;i<n;++i){
		if(s1[i]=='0'&&s2[i]=='1')c1++;
		if(s1[i]=='1'&&s2[i]=='0')c2++;
	}
	cout<<max(c1,c2)<<"\n";

}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
}
