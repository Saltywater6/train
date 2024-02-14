#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int>deg(n);
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		a--,b--;
		deg[a]++,deg[b]++;
	}
	if(n%2==0&&m%2==0)cout<<0<<endl;
	if(n%2==0&&m%2==1)cout<<m<<endl;
	if(n%2==1&&m%2==0){
		int ans=0;
		for(int i=0;i<n;++i)
			if(deg[i]%2==0)ans++;
		cout<<ans<<endl;
	}

	if(n%2==1&&m%2==1){
		int ans=0;
		for(int i=0;i<n;++i)
			if(deg[i]&1)ans++;
		cout<<ans<<endl;

	}
}
	
