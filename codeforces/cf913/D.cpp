#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>l,r;
bool check(int op){
	int L=0,R=0;
	for(int i=0;i<n;++i){
		L-=op,R+=op;
		L=max(L,l[i]);
		R=min(R,r[i]);
		if(L>R)return 0;
	}
	return 1;
}
void solve(){
	cin>>n;
	l.resize(n),r.resize(n);
	for(int i=0;i<n;++i)
		cin>>l[i]>>r[i];

	int L=0,R=1e9,ans=1e9;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)){
			R=mid-1,ans=mid;
		}else L=mid+1;
	}
	cout<<ans<<"\n";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
}
