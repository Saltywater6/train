#include<bits/stdc++.h>
using namespace std;

using ll = long long ;

void solve() {
	string a,b,c;
	int n;
	cin>>n>>a>>b>>c;
	bool fl=1;
	for(int i=0;i<n;++i){
		if(c[i]!=b[i]&&c[i]!=a[i])fl=0;
	}
	puts(fl?"NO":"YES");


}

int main() {
	cin.tie()->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--) solve();
	return  0;
}

