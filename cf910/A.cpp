#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	string s;
	cin>>n>>m>>s;
	int cnt=0;
	for(int i=0;i<n;++i)if(s[i]=='B')cnt++;
	if(cnt==m){
		cout<<"0\n";
	}else{
		int c1=0,c2=0;
		for(int i=0;i<n;++i){
			if(s[i]=='A')c1++;
			else c2++;
			if(c1+cnt==m){
				cout<<"1\n"<<i+1<<" B\n";
				return ;
			}
			if(cnt-c2==m){
				cout<<"1\n"<<i+1<<" A\n";
				return ;
			}
		}
		cout<<"2\n"<<n<<" A\n"<<m<<" B\n";
	}
	

}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
