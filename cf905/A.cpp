#include<bits/stdc++.h>
using namespace std;

char s[10];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		s[0]=1;
		int ans=0;
		for(int i=1;i<=4;++i){
			s[i]-='0';
			if(s[i]==0)s[i]+=10;
			ans+=abs(s[i]-s[i-1]);
		}
		printf("%d\n",ans+4);
	}
}
