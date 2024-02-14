#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,P;
	scanf("%d%d",&n,&P);
	int ans=P;
	if(P!=4){
		for(int i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			ans=min(ans,P-(x-1)%P-1);
		}
		printf("%d\n",ans);
	}else{
		int c1=0,c2=0,c4=0,c3=0;
		for(int i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			if(x%4==0)c4++;
			if(x%4==3)c3++;
			if(x%4==2)c2++;
			if(x%4==1)c1++;
		}
		if(c4||c2>=2)puts("0");
		else if(c3||c2&&c1)puts("1");
		else if(c2||c1>=2)puts("2");
		else puts("3");
	}
}
int main(){
	//freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
}
