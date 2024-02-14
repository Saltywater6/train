#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=6;++i)
		for(int j=1;j<=6;++j){
			if(i%3==0||j%3==0||i==j)continue;
			if(n<=i+j)continue;
			if((n-i-j)%3==0)continue;
			if(n-i-j==i||n-i-j==j)continue;
			cout<<"Yes\n";
			cout<<i<<" "<<j<<" "<<n-i-j<<"\n";
			return ;
		}
	cout<<"No\n";
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
