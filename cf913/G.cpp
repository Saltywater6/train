#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	string s;
	cin>>n>>s;
	vector<int>A(n),ind(n),ans;
	for(int i=0;i<n;++i){
		cin>>A[i];
		++ind[--A[i]];
	}
	queue<int>que;
	for(int i=0;i<n;++i)if(ind[i]==0)que.push(i);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		if(--ind[A[x]]==0)que.push(A[x]);
		if(s[x]=='0')continue;
		s[x]='0';
		s[A[x]]^=1;
		ans.push_back(x+1);
	}
	for(int i=0;i<n;++i)if(ind[i]){
		int x=i;
		int t=0,len=0,res=0;
		while(ind[x]){
			if(s[x]=='1')t^=1;
			res+=t;
			ind[x]=0;
			len++;
			x=A[x];
		}
		if(t&1){
			cout<<"-1\n";
			return ;
		}
		for(int k=0;k<len;++k){
			if(s[x]=='1')t^=1;
			if(t==(res<len-res))
				ans.push_back(x+1);
			x=A[x];
		}
	}
	cout<<ans.size()<<"\n";
	for(int x:ans)cout<<x<<" ";
	cout<<"\n";
}




int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
}
