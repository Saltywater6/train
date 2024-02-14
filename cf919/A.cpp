#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>>A(n);
	for(int i=0;i<n;++i){
		cin>>A[i].second>>A[i].first;
		if(A[i].second>1)A[i].second=5-A[i].second;
	}
	sort(A.begin(),A.end());
	int l=0,r=n-1;
	for(int i=0;i<n;++i)if(A[i].second==1)l=i;
	for(int i=n-1;i>=0;--i)if(A[i].second==3)r=i;
	if(l<r){
		cout<<A[r].first-A[l].first-(r-l-1)+1<<endl;
	}else cout<<0<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0 ;
}
