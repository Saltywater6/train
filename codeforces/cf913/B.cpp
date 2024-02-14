#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s,ans;
	cin>>s;
	int c1=0,c2=0;
	for(int i=s.length()-1;i>=0;--i){
		if(s[i]=='b')c1++;
		else if(s[i]=='B')c2++;
		else if(s[i]>='a'&&s[i]<='z'){
			if(c1)--c1;
			else ans+=s[i];
		}else if(s[i]>='A'&&s[i]<='Z'){
			if(c2)--c2;
			else ans+=s[i];
		}
	}
	for(int i=ans.size()-1;i>=0;--i)
		cout<<ans[i];
	cout<<"\n";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
}
