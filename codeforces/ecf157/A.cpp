#include<bits/stdc++.h>
using namespace std;

void solve(){
	int x,y,k;
	scanf("%d%d%d",&x,&y,&k);
	if(x+k>=y)printf("%d\n",max(x,y));
	else {
		x+=k;
		printf("%d\n",y+y-x);
	}
}
int main(){
	//freopen("hayasa","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)solve();
}
