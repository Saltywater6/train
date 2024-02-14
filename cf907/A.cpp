#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int A[M];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	for(int i=2;i<=n;++i){
		int t=1<<(i-1);
		if(t>=n)break;
		for(int j=t+2;j<=min(n,t*2);++j){
			if(A[j-1]>A[j]){
				puts("NO");
				return ;
			}
		}
	}
	puts("YES");
}

int main(){
	//freopen("hayasa","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
}
