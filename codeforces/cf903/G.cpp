#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	string s;
	cin>>n>>m>>s;
	vector<int>A(n-1);
	for(int i=0;i<n-1;++i)
		A[i]=(s[i]-s[i+1]+26)%26;
	set<int>s1,s2;
	for(int i=0;i<n-1;++i)
		if(A[i]==0)s1.insert(i);
	for(int i=0;i+1<n-1;++i)
		if(A[i]+A[i+1]==26)s2.insert(i);
	while(m--){
		int op,l,r,x;
		cin>>op>>l>>r;
		l--,r--;
		if(op==1){
			cin>>x;
			s1.erase(l-1);
			s1.erase(r);
			s2.erase(l-2);
			s2.erase(r);
			s2.erase(l-1);
			s2.erase(r-1);

			if(l>0)A[l-1]=(A[l-1]+26-x%26)%26;
			if(r<n-1)A[r]=(A[r]+x%26)%26;

			if(l>0&&A[l-1]==0)s1.insert(l-1);
			if(r<n-1&&A[r]==0)s1.insert(r);

			if(l>=2&&A[l-2]+A[l-1]==26)s2.insert(l-2);
			if(r+1<n-1&&A[r]+A[r+1]==26)s2.insert(r);

			if(l>0&&A[l-1]+A[l]==26)s2.insert(l-1);
			if(r-1>=0&&r<n-1&&A[r-1]+A[r]==26)s2.insert(r-1);
		}else{
			auto it1=s1.lower_bound(l);
			auto it2=s2.lower_bound(l);
			bool ans=0;
			ans|=(it1!=s1.end()&&(*it1)+1<=r);
			ans|=(it2!=s2.end()&&(*it2)+2<=r);
			cout<<(ans?"NO":"YES")<<"\n";
		}
	}
}
	
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
