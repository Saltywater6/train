#include<bits/stdc++.h>
using namespace std;

using ll=long long ;
#define endl '\n'

void solve(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;++i)cin>>A[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		if(n%i==0){
			int g=0;
			for(int j=i;j<n;++j)
				g=gcd(g,A[j]-A[j-i]);
			ans+=(g!=1);
		}
	}
	cout<<ans<<endl;

}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
