#include<bits/stdc++.h>
using namespace std;

using ll = long long ;

const int M=3e5+10;
int A[M],B[M],pre[M],nxt[M];
bool liv[M];
int getpre(int x){
	return pre[x]==x?x:pre[x]=getpre(pre[x]);
}
int getnxt(int x){
	return nxt[x]==x?x:nxt[x]=getnxt(nxt[x]);
}
void solve() {
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>A[i];
	for(int i=1;i<=n;++i)cin>>B[i];
	for(int i=1;i<=n;++i)pre[i]=nxt[i]=i,liv[i]=0;
	nxt[n+1]=pre[n+1]=A[n+1]=0;
	queue<int>que;
	for(int i=1;i<=n;++i)
		if(B[i]<A[i-1]+A[i+1])que.push(i);
	for(int T=1;T<=n;++T){
		int ans=0;
		queue<int>tmp;
		vector<int>stk;
		while(!que.empty()){
			auto x=que.front();
			que.pop();
			if(liv[x])continue;
			int l=getpre(x-1),r=getnxt(x+1);
			//cout<<x<<"-"<<T<<" "<<l<<" "<<r<<endl;;
			if(B[x]<A[l]+A[r]){
				ans++,liv[x]=1;
				stk.push_back(x);
				if(l)tmp.push(l);
				if(r)tmp.push(r);
			}
		}
		while(!stk.empty()){
			auto x=stk.back();
			stk.pop_back();
			int l=getpre(x-1),r=getnxt(x+1);
			pre[x]=l,nxt[x]=r;
		}
		cout<<ans<<" ";
		swap(tmp,que);
	}
	cout<<"\n";
	
			
}

int main() {
	cin.tie()->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--) solve();
	return  0;
}

