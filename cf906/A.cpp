#include<bits/stdc++.h>
using namespace std;

const int M=105;
int A[M];
void solve(){
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	int cnt=0,pos;
	for(int i=2;i<=n;++i){
		if(A[i]!=A[i-1])cnt++,pos=i-1;
	}
	if(cnt>1){
		puts("No");
		return ;
	}
	if(cnt==0){
		puts("Yes");
		return ;
	}
	if(abs(pos-(n-pos))<=1){
		puts("Yes");
	}else puts("No");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
}
