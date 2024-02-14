#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
char s[M],t[M];
vector<int>ans;
int n;
bool check(){
	for(int i=1;i<=n;++i)
		if(s[i]==s[n-i+1])return 0;
	return 1;
}
void ins(int x){
	ans.push_back(x);
	int cnt=0;
	for(int i=1;i<=x;++i)
		t[++cnt]=s[i];
	t[++cnt]='0';
	t[++cnt]='1';
	for(int i=x+1;i<=n;++i)
		t[++cnt]=s[i];
	for(int i=1;i<=cnt;++i)s[i]=t[i];
	n=cnt;
}
void solve(){
	ans.clear();
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=300;++i){
		for(int i=1;i<=n;++i){
			if(s[i]==s[n-i+1]){
				if(s[i]=='0')ins(n-i+1);
				else ins(i-1);
				break;
			}
		}
		if(check())break;
	}
	if(check()){
		printf("%d\n",(int)ans.size());
		for(int x:ans)printf("%d ",x);
		puts("");
	}else puts("-1");
}
int main(){
	//freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
						
