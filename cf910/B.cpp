#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;++i)cin>>A[i];
	int pre=A[n-1];
	long long ans=0;
	for(int i=n-2;i>=0;--i){
		//cout<<i<<" "<<pre<<endl;
		int t=(A[i]-1)/pre+1;
		ans+=t-1;
		pre=A[i]/t;
	}
	cout<<ans<<"\n";

}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
