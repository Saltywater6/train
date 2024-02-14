#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,p;
	cin>>n>>p;
	vector<array<int,2>>A(n);
	for(auto &[x,y]:A)cin>>y;
	for(auto &[x,y]:A)cin>>x;
	sort(A.begin(),A.end());
	int r=n-1;
	long long ans=p;
	for(int l=0;l<r;++l){
		if(A[l][0]>=p){
			ans+=1ll*(r-l)*p;	
			break;
		}else{
			if(r-l>A[l][1]){
				r=r-A[l][1]+1;
				ans+=1ll*A[l][1]*A[l][0];
			}else {
				ans+=1ll*(r-l)*A[l][0];
				break;
			}
		}
	}
	cout<<ans<<"\n";
}	
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
