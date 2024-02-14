#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<n;++i){
		int x;
		cin>>x;
		sum-=x;
	}
	cout<<sum<<"\n";
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
