#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	vector<int>A(2*n);
	for(int i=0;i<2*n;++i)
		scanf("%d",&A[i]);
	sort(A.begin(),A.end());
	int ans=0;
	for(int i=0;i<n-1;i++)
		ans=ans+A[i+1]-A[i]+A[i+n+1]-A[i+n];
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		printf("%d %d\n",A[i+n],A[i]);
}
int main(){
	//freopen("hayasa","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)solve();
}


