#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
bool vis[M];
int s[M],ans[M],top;
stack<int>stk[M];
int dfs(int x){
	if(ans[x])return ans[x];
	if(stk[x].empty())
		return x;
	if(vis[x]){
		s[top+1]=0;
		while(s[top+1]!=x){
			stk[s[top]].pop();
			vis[s[top]]=0;
			top--;
		}
		return dfs(x);
	}
	s[++top]=x;
	vis[x]=1;
	return dfs(stk[x].top());
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		while(k--){
			int t;
			scanf("%d",&t);
			stk[i].push(t);
		}
	}
	for(int i=1;i<=n;++i){
		int res=dfs(i);
		while(top)ans[s[top--]]=res;
		printf("%d ",res);
	}
}
