#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>b(n);
	int ans=1;
	for(int i=0;i<n;++i){
		cin>>b[i];
	}
	for(int i=0;i<n;++i){
		ans=ans*b[i];
		if(ans>2023){
			cout<<"NO\n";
			return ;
		}
	}
	if(2023%ans){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
		int ans=2023;
		for(int i=0;i<n;++i){
			while(b[i]%7==0)b[i]/=7,ans/=7;
			while(b[i]%17==0)b[i]/=17,ans/=17;
		}
		if(k){
			cout<<ans<<" ";
		    for(int i=1;i<k;++i)
				cout<<"1 ";
			cout<<"\n";
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
