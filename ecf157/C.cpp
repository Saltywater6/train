#include<bits/stdc++.h>
using namespace std;

using ll=long long ;
int buc[10][50];
int main(){
	//freopen("hayasa","r",stdin);
	int n;
	scanf("%d",&n);
	vector<int>A(n);
	for(int i=0;i<n;++i)
		scanf("%d",&A[i]);
	sort(A.begin(),A.end());
	ll ans=0;
	vector<int>s(10);
	for(int j=0;j<n;++j){
		int t=A[j],C=0;
		while(t){
			s[C+1]=s[C]+t%10;
			t/=10,C++;
		}
		for(int i=1;i<=C;++i){
			if(2*i<=C)continue;
			if(s[i]-s[C]+s[i]>=0)ans+=buc[2*i-C][s[i]-(s[C]-s[i])];
			if(s[C]-2*s[C-i]>=0)ans+=buc[2*i-C][s[C]-s[C-i]-s[C-i]];
		}
		buc[C][s[C]]++;
	}
	printf("%lld\n",ans+n);
}

