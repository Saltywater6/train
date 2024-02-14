#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	if(k<n-1+m-1||(k-(n-1+m-1))&1){
		cout<<"No\n";
	}else {
		cout<<"Yes\n";
		for(int i=0;i<n;++i){
			for(int j=0;j<m-1;++j){
				if(i==1&&j==0)cout<<"B ";
				else if((i+j)&1)cout<<"R ";
				else cout<<"B ";
			}
			cout<<"\n";
		}
		for(int i=0;i<n-1;++i){
			for(int j=0;j<m;++j)
				if(i==0&&j==0)cout<<"R ";
				else if((i+j)&1)cout<<"R ";
				else cout<<"B ";
			cout<<"\n";
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
