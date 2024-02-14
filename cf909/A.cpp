#include<bits/stdc++.h>
using namespace std;

void solve(){

	int n;
	cin>>n;
	if(n%3)cout<<"First\n";
	else cout<<"Second\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
