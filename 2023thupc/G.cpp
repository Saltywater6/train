#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int m;
	cin>>m;
	vector<int>A(m),B,C,mk(m);
	for(int i=0;i<m;++i)cin>>A[i];
	string ans="";
	if(B.empty()&&C.empty()){
		cout<<"Cleared.\n";
		cout<<ans.length()<<"\n";
		cout<<ans;
	}else cout<<"No solution.\n";
}
