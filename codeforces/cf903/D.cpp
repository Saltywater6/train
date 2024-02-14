#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
vector<vector<int>>D(M);
int cnt[M];
void init(){
	for(int i=2;i<M;++i)if(D[i].empty())
		for(int j=i;j<M;j+=i)
			D[j].emplace_back(i);
}
void solve(){
	int n;
	cin>>n;
	int tot=0;
	vector<int>clr;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		int t=x;
		for(int y:D[x]){
			clr.emplace_back(y);
			while(t%y==0){
				tot-=(cnt[y]%n!=0);
				cnt[y]++;
				//cout<<y<<" "<<x<<endl;
				tot+=(cnt[y]%n!=0);
				t/=y;
			}
		}
	}
	for(int x:clr)cnt[x]=0;
	//for(int i=0;i<M;++i)if(cnt[i])cout<<i<<" "<<cnt[i]<<endl;
	cout<<(tot?"NO":"YES")<<"\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	init();
	int T;
	cin>>T;
	while(T--)solve();
}
