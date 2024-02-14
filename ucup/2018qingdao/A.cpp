#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("hayasa","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,a;
		scanf("%d%d",&n,&a);
		int b=n-a;
		printf("%d %d\n",a,(n/(b+1)));
	}
}
