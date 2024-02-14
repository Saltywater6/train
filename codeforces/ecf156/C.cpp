#include<bits/stdc++.h>
using namespace std;


void solve(){
	string s;
	long long pos;
	cin>>s>>pos;
	pos--;
	int n=s.length(),x;
	for(int i=0;i<n;++i){
		int len=n-i;
		if(pos<len){
			x=i;
			break;
		}
		pos-=len;
	}
	string t;
	for(auto c:s){
		while(x&&!t.empty()&&t.back()>c)
			t.pop_back(),x--;
		t+=c;
	}
	cout<<t[pos];
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
