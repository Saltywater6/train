#include<bits/stdc++.h>
using namespace std;

constexpr int mod=998244353;
vector<int>fa;
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void Merge(int x,int y){
	fa[getfa(x)]=getfa(y);
}
void solve(){
	int n,m=0;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;++i){
		cin>>A[i];
		m=max(m,A[i]--);
	}
	vector<int>R(m,-1);
	fa.resize(m);
	for(int i=0;i<n;++i)R[A[i]]=i;
	for(int i=0;i<m;++i)fa[i]=i;
	int ans=1;
	for(int i=0;i<n;++i)if(R[A[i]]==i)ans=ans*2%mod;
	vector<int>cur(m);
	vector<vector<int>> B(2);
	int v=0;
	for(int i=0,j=0;i<n;++i){
		B[cur[A[i]]].push_back(A[i]);
		v-=cur[A[i]];
		cur[A[i]]^=1;
		v+=cur[A[i]];
		if(!v){
			for(;j<=i;++j)
				Merge(A[j],A[i]);
		}
		//cout<<j<<" "<<i<<endl;
	}
	if(B[0]==B[1]){
		int val=1;
		for(int i=0;i<m;++i)if(R[i]>=0&&fa[i]==i)val=val*2%mod;
		ans=(ans-val+mod)%mod;
	}
	cout<<1ll*(mod+1)/2*ans%mod<<"\n";
}
		
	
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("data.in","r",stdin);
	freopen("std.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)solve();
}
