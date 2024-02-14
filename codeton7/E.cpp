#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
struct BIT{
	int f[M];
	void upd(int x,int k){
		x++;
		while(x<M)f[x]+=k,x+=x&-x;
	}
	int qry(int x){
		x++;
		int res=0;
		while(x)res+=f[x],x-=x&-x;
		return res;
	}
};

void solve(){
	int n;
	cin>>n;
	vector<int>A(2*n),ans(2*n,-1),pos(2*n,-1);
	for(int i=0;i<n;++i){
		cin>>A[i];
		A[i+n]=A[i];
	}
	for(int i=0;i<2*n;++i){
		if(pos[A[i]]!=-1)T.upd(pos[A[i]].-1);
		pos[A[i]]=i;
		if(pos[i%n]!=-1){
			ans[i]=(i-pos[i%n])-(T.qry(M-1)-T.qry(pos[i%n]-1));
			T.upd(pos[i%n],1);
		}
	}
	for(int i=0;i<n;++i)cout<<ans[i+n]<<" ";
	cout<<"\n";
}


int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
