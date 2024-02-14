#include<bits/stdc++.h>
using namespace std;


using ll=long long ;
const int M=1e6+10;
int ch[M][26],tot,cnt[M];
ll mp[26][26];

int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(0)->sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	ll bas=0;
	for(int i=1;i<=n;++i){
		int cur=0;
		string s;
		cin>>s;
		cnt[cur]++;
		for(auto c:s){
			int t=c-'a';
			if(!ch[cur][t])ch[cur][t]=++tot;
			for(int j=0;j<26;++j){
				if(t==j)continue;
				if(ch[cur][j])mp[t][j]+=cnt[ch[cur][j]];
			}
			cur=ch[cur][t];
			cnt[cur]++;
		}
		for(int j=0;j<26;++j)
			if(ch[cur][j])bas+=cnt[ch[cur][j]];
	}
	while(q--){
		string per;
		cin>>per;
		ll ans=bas;
		for(int i=0;i<26;++i)
			for(int j=i+1;j<26;++j)
				ans+=mp[per[i]-'a'][per[j]-'a'];
		cout<<ans<<"\n";
	}
}

