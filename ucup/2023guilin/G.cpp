#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
char s[M];
void solve(){
	scanf("%s",s);
	int cnt=0;
	int n=strlen(s);
	for(int i=0;i<n;++i)
		s[i]=='('?++cnt:cnt=max(0,cnt-1);
	if(cnt)
		cout<<"impossible\n";
	else cout<<s<<"\n";
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}

