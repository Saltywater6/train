#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	string s,t;
	cin>>n>>m>>s>>t;
	vector<int> fir(26,m);
	for(int i=m-1;i>=0;--i)fir[t[i]-'a']=i;
	for(char c:s){
		int ch=c-'a';
		if(fir[ch]!=m){
			bool fl=1;
			for(int i=ch+1;i<26;++i)
				if(fir[i]<fir[ch])fl=0;
			if(fl){
				fir[ch]++;
				while(fir[ch]<m &&t[fir[ch]]!='a'+ch)
					fir[ch]++;
			}
		}
	}
	cout<<(ranges::count(fir,m)==26?"YES":"NO")<<"\n";

}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
