#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int mnx,mxx,mny,mxy;
	mnx=mny=1001;
	mxx=mxy=-1001;
	for(int i=0;i<4;++i){
		int x,y;
		cin>>x>>y;
		mnx=min(mnx,x);
		mny=min(mny,y);
		mxx=max(mxx,x);
		mxy=max(mxy,y);
	}
	cout<<(mxy-mny)*(mxx-mnx)<<"\n";
		
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
}
