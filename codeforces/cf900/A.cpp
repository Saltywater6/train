#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>A(n);
	for(int i=0;i<n;++i)cin>>A[i];
	for(int i=0;i<n;++i){
		vector<int>cnt(101,0);
		for(int j=i;j<n;++j){
			cnt[A[i]]++;
			if(*max_element(cnt.begin(),cnt.end())==cnt[k]){
				cout<<"Yes\n";
				return ;
			}
		}
	}
	cout<<"No\n";
}


int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
