#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(auto &x:A)cin>>x;
	int mn=A[0];
	for(int i=0;i<n;++i)
		if(mn>A[i])mn=A[i];
	for(int i=0;i<n;++i){
		if(A[i]==mn){
			for(int j=i+1;j<n;++j){
				if(A[j]<A[j-1]){
					cout<<"-1\n";
					return ;
				}
			}
			cout<<i<<"\n";
			return ;
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
