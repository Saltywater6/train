#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	if(n<=2){
		cout<<"0\n";
		return ;
	}
	int Mx=n+1,mx=n+1;
	int ans=0;
	for(int i=0;i<n;++i){
		if(Mx<mx)swap(Mx,mx);
		if(a[i]<=mx)mx=a[i];
		else if(a[i]>mx&&a[i]<=Mx)
			Mx=a[i];
		else mx=a[i],ans++;
	}
	cout<<ans<<"\n";

	return ;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
}
