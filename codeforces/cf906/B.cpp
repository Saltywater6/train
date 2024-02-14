#include<bits/stdc++.h>
using namespace std;

const int M=1e5+01;
char S[M],T[M];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",S+1,T+1);
	bool fl=1;
	for(int i=1;i<m;++i)
		if(T[i]==T[i+1])fl=0;
	for(int i=1;i<n;++i)
		if(S[i]==S[i+1])
			if(!(fl&&m&1&&T[1]!=S[i])){
				puts("No");
				return ;
			}
	puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
}
