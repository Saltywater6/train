#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int cnt[30];
char s[M];
void solve(){
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=0;i<26;++i)cnt[i]=0;
	for(int i=1;i<=n;++i)
		cnt[s[i]-'a']++;
	int C=0,fl=0;
	for(int i=0;i<26;++i)
		if(cnt[i]&1){
			if(!fl)fl=1;
			else C++;
		}
	puts(C<=q?"Yes":"No");
}
int main(){
	//freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
}

