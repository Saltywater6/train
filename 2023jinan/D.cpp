#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;

void solve(){
	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	if((l1+l2)/10==(r1+r2)/10){
		int ans=0;
		int t=r1+r2;
		while(t)ans=max(ans,t%10),t/=10;
		cout<<ans<<endl;
	}else cout<<9<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
}
