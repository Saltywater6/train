#include<bits/stdc++.h>
using namespace std;

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	long long sum=1ll*a+b+c;
	for(int i=3;i<=6;++i){
		if(sum%i==0){
			int t=sum/i;
			//cout<<t<<endl;
			if(a%t==0&&b%t==0&&c%t==0){
				cout<<"YES\n";
				return ;
			}
		}
	}
	cout<<"NO\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
