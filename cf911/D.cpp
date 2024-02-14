#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
vector<int>G[M];
int t[M];
void init(){
	for(int i=1;i<=1e5;++i)
		for(int j=i;j<=1e5;j+=i)
			G[j].push_back(i);
	for(int i=1;i<=1e5;++i)
		sort(G[i].begin(),G[i].end(),greater());
}
void solve(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;++i)cin>>A[i];
	ranges::sort(A);
	long long sum=0,ans=0;
	vector<int>cnt(M);
	for(int i=0;i<n;++i){
		ans+=sum;
		for(int x:G[A[i]]){
			sum+=1ll*(cnt[x]-t[x])*x;
			for(int y:G[x]){
				if(y!=x)
				t[y]+=cnt[x]-t[x];
			}
			cnt[x]++;
		}
		for(int x:G[A[i]])t[x]=0;
		//cout<<i+1<<" "<<ans<<" "<<sum<<endl;
	}
	cout<<ans<<endl;

}
int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	init();
	while(T--)solve();
}

