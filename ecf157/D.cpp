#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
int s[M][2],t[M][2];
int main(){
	//freopen("hayasa","r",stdin);
	int n;
	scanf("%d",&n);
	vector<int>A(n),B(n);
	for(int i=0;i<n-1;++i)
		scanf("%d",&A[i]);
	for(int i=1;i<n;++i)
		B[i]=B[i-1]^A[i-1];
	for(int i=0;i<n;++i)
		for(int j=0;j<20;++j)
			s[j][i>>j&1]++;
	for(int i=0;i<n;++i)
		for(int j=0;j<20;++j)
			t[j][B[i]>>j&1]++;
	int ans=0;
	for(int j=0;j<20;++j)
		if(s[j][0]!=t[j][0])ans|=1<<j;
	for(int i=0;i<n;++i)
		printf("%d ",B[i]^ans);
	puts("");
}

