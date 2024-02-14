#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int>A(2*n+1),B(2*n+1);
	for(int i=1;i<=n;++i)
		cin>>A[i],A[i+n]=A[i];
	for(int i=1;i<=2*n;++i)B[i]=A[i];
	auto calc=[&]()->int{
		//dir
		vector<int>s(2*n+1);
		int ans=1e9;	
		//for(int i=1;i<=2*n;++i)cout<<B[i]<<" ";
		for(int i=2*n-1;i;--i)
			s[i]=s[i+1]+(B[i]>B[i+1]);
	//	cout<<endl;
	//	for(int i=1;i<=2*n;++i)cout<<s[i]<<" ";
	//	cout<<endl;
		for(int i=0;i<n;++i)
			if(s[n+1-i]-s[2*n-i]==0)
				ans=min(ans,i);
		//dir+rev
		for(int i=2*n-1;i;--i)
			s[i]=s[i+1]+(B[i]<B[i+1]);
		for(int i=0;i<n;++i)
			if(s[n+1-i]-s[2*n-i]==0)
				ans=min(ans,i+1);
		return ans;
	};
	int res=calc();
	for(int i=1;i<=n;++i)
		swap(B[i],B[2*n-i+1]);
	res=min(res,calc()+1);
	cout<<(res==1e9?-1:res)<<"\n";
}
	
int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
}
