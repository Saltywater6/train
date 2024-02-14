#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
char s[M];
void solve(){
	int n;
	cin>>n>>s;
	cout<<s[n-1]<<"\n";
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
