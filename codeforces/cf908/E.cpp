#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void solve(){
	int m;
	cin>>m;
	vector<vector<ll>> A(m),C(m);
	vector<int> n(m);
	vector<ll> l(m),r(m),sum(m),T;
	ll L=0,R=0;
	for(int i=0;i<m;++i){
		cin>>n[i]>>l[i]>>r[i];
		L+=l[i],R+=r[i];
		A[i].resize(n[i]);
		C[i].resize(n[i]);
		for(auto &x:A[i])cin>>x,T.emplace_back(x);
		for(auto &x:C[i])cin>>x,sum[i]+=x;
	}
	sort(T.begin(),T.end());
	vector<vector<int>>G(T.size());
	for(int i=0;i<m;++i)
		for(auto x:A[i]){
			int tmp=lower_bound(T.begin(),T.end(),x)-T.begin();
			G[tmp].emplace_back(i);
		}
	ll ans=-1;
	for(ll i=L;i<=R;++i){
		int t=lower_bound(T.begin(),T.end(),i)-T.begin();
		if(t>=T.size()||T[t]!=i){
			cout<<"0\n";
			return ;
		}
		ll res=0,cnt=R;
		for(auto x:G[t]){
			cnt-=r[x];
			int p=lower_bound(A[x].begin(),A[x].end(),i)-A[x].begin();
			if(sum[x]-C[x][p]<l[x]){
				cnt+=l[x],res+=l[x]-(sum[x]-C[x][p]);
			}else cnt+=min(r[x],sum[x]-C[x][p]);
		}
		res+=max(0ll,i-cnt);
		if(ans==-1||ans>res)ans=res;
	}
	cout<<ans<<"\n";
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
}




