#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	vector<int>buc(200);
	for(auto c:s)buc[c]++;
	cout<<max(n&1,*max_element(buc.begin(),buc.end())*2-n)<<"\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
}
