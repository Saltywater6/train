#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<n;++i)
		cout<<i<<" "<<i+1<<"\n";
	int nw=n-1;
	while(q--){
		int d;
		cin>>d;
		if(nw==d||nw!=n-1&&d==n-2)cout<<"-1 -1 -1\n";
		else cout<<n<<" "<<nw<<" "<<d<<"\n",nw=d;
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T=1;
	cin>>T;
	while(T--)solve();
}
