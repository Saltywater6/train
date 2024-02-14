#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;


const int M=1e6+10;
struct Trie{
	int ch[M][2],s[M],tot;
	ll ord[M],inv[M];
	void insert(int x){
		int cur=0;
		for(int i=20;i>=0;--i){
			int t=x>>i&1;
			if(!ch[cur][t])ch[cur][t]=++tot;
			if(t==1)ord[i]+=s[ch[cur][0]];
			else inv[i]+=s[ch[cur][1]];
			cur=ch[cur][t];
			++s[cur];
		}
	}	
}Tr;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		Tr.insert(x);
	}
	ll ans1=0,ans2=0;
	for(int i=0;i<=20;++i){
		ans1+=Tr.inv[i];
		ans2+=min(Tr.inv[i],Tr.ord[i]);
	}
	cout<<min(ans1,ans2+1);
}
