#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	if(k==1)cout<<"1\n";
	else if(k>=4)cout<<"0\n";
	else if(m>=n){
		if(k==2)cout<<m/n+n-1<<"\n";
		if(k==3)cout<<m-m/n-n+1<<"\n";
	}else{
		if(k==2)cout<<m<<"\n";
		if(k==3)cout<<0<<"\n";
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
