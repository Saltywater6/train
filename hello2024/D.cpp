#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define endl '\n'

void solve(){
	int n;
	cin>>n;
	vector<int>A(n),stk,tag(n);
	for(int i=0;i<n;++i)cin>>A[i];
	for(int i=0;i<n;++i){
		while(!stk.empty()&&stk.back()>=A[i])
			stk.pop_back();
		if(!stk.empty()&&stk.back()==A[i]-1)
			tag[i]=1;
		stk.emplace_back(A[i]);
	}
	stk.clear();
	for(int i=n-1;i>=0;--i){
		while(!stk.empty()&&stk.back()>=A[i])
			stk.pop_back();
		if(!stk.empty()&&stk.back()==A[i]-1)
			tag[i]=1;
		stk.emplace_back(A[i]);
	}
	int C=0,D=0;;
	for(auto x:tag)if(x==0)C++;
	for(auto x:A)if(x==0)D++;
	cout<<(C==1&&D==1?"YES":"NO")<<endl;
	
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
