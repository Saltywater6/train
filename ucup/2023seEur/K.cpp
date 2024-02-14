#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;


void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>A(n);
	set<pair<int,int>>s;
	for(int i=0;i<k;++i){
		s.insert({0,i+1});
	}
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(x==1){
			auto tmp=*s.begin();
			s.erase(s.begin());
			tmp.first++;
			s.insert(tmp);
			cout<<tmp.second<<" ";
		}else{
			auto tmp=*--s.end();
			s.erase(--s.end());
			tmp.first=max(0,tmp.first-1);
			s.insert(tmp);
			cout<<tmp.second<<" ";
		}
	}
	cout<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
