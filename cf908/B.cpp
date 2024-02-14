#include<bits/stdc++.h>
using namespace std;

int cnt[200];
void solve(){
	int n;
	cin>>n;
	vector<int>A(n),ans(n);
	for(auto &x:A)cin>>x,cnt[x]++;
	int C=0;
	for(int i=1;i<=100;++i)
		if(cnt[i]>=2)C++;
	if(C<2){
		for(int i=0;i<n;++i)cnt[A[i]]--;
		cout<<"-1\n";
		return ;
	}
	int tag=1;
	for(int i=0;i<n;++i){
		if(ans[i]==0&&cnt[A[i]]>1){
			ans[i]=tag;
			++tag;
			for(int j=i+1;j<n;++j)
				if(A[j]==A[i])ans[j]=tag;
			if(tag==3)break;
		}
	}
	for(int i=0;i<n;++i)cnt[A[i]]--;
	for(int i=0;i<n;++i)if(ans[i]==0)ans[i]=1;
	for(int i=0;i<n;++i)cout<<ans[i]<<" ";
	cout<<"\n";
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
