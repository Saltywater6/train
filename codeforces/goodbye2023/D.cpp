#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void solve(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"1\n";
		return;
	}
	for(int j=0;j<=(n-3)/2;++j){
		cout<<"1";
		for(int k=1;k<=j;++k)
			cout<<"0";
		cout<<"6";
		for(int k=1;k<=j;++k)
			cout<<"0";
		cout<<"9";
		for(int k=n-3-j*2;k;--k)
			cout<<"0";
		cout<<"\n";
	}
	for(int j=0;j<=(n-3)/2;++j){
		cout<<"9";
		for(int k=1;k<=j;++k)
			cout<<"0";
		cout<<"6";
		for(int k=1;k<=j;++k)
			cout<<"0";
		cout<<"1";
		for(int k=n-3-j*2;k;--k)
			cout<<"0";
		cout<<"\n";
	}
	cout<<"196";
	for(int i=3;i<n;++i)
		cout<<"0";
	cout<<"\n";

}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
