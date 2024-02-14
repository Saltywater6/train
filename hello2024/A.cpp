#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
	int a,b;
	cin>>a>>b;
	if((a&1)==(b&1))cout<<"Bob"<<"\n";
	else cout<<"Alice"<<"\n";

}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
}
