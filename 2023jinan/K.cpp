#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

void solve(){
	string s;
	cin>>s;
	int n=s.length();
	vector<int>A(n),B(n),stk;
	for(int i=0;i<n;++i)
		if(s[i]==')'||s[i]=='(')s[i]=0;
		else s[i]=1;
	for(int i=0;i<n;++i){
		if(!stk.empty()){
			if(s[stk.back()]==s[i]){
				A[stk.back()]=i,A[i]=stk.back();
				stk.pop_back();
			}else stk.push_back(i);
		}else stk.push_back(i);
	}
	auto dfs=[&](auto self,int l,int r)->void{
		if(l>r)return ;
		for(int i=r;i>=l;--i){
			if(stk.empty()&&s[i]==s[l]){
				B[l]=i,B[i]=l;
				self(self,l+1,i-1);
				self(self,i+1,r);
				break;
			}
			if(!stk.empty()&&s[stk.back()]==s[i])
				stk.pop_back();
			else stk.push_back(i);
		}
	};
	dfs(dfs,0,n-1);
	bool fl=1;
	for(int i=0;i<n;++i)if(A[i]!=B[i])fl=0;
	cout<<(fl?"Yes":"No")<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)solve();
}
