#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int>stk,A(n),B(n);
	vector<int>ind(n),deg(n);
	vector<vector<int>>G(n);
	vector<pair<int,int>>ans;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		--x;
		A[i]=x;
		while(!stk.empty()&&stk.back()<x)
			stk.pop_back();
		if(!stk.empty()){
			ans.emplace_back(stk.back(),x);
			G[stk.back()].emplace_back(x);
			++ind[x];
		}
		stk.emplace_back(x);
	}
	stk.clear();
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		--x;
		B[i]=x;
		while(!stk.empty()&&stk.back()>x)
			stk.pop_back();
		if(!stk.empty()){
			ans.emplace_back(stk.back(),x);
			G[stk.back()].emplace_back(x);
			++ind[x];
		}
		stk.emplace_back(x);
	}
	queue<int>que;
	deg=ind;
	for(int i=0;i<n;++i)if(!ind[i])que.push(i);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		for(auto y:G[x])
			if(--ind[y]==0)que.push(y);
	}
	for(int i=0;i<n;++i){
		if(ind[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}	

	ind=deg;
	priority_queue<int>qmax;
	for(int i=0;i<n;++i)if(ind[i]==0)qmax.push(i);
	int p=0;
	while(!qmax.empty()){
		auto x=qmax.top();
		qmax.pop();
		if(x!=B[p++]){
			cout<<"No"<<endl;
			return 0;
		}
		for(auto y:G[x])
			if(--ind[y]==0)qmax.push(y);
	}
	ind=deg;
	priority_queue<int>qmin;
	for(int i=0;i<n;++i)if(ind[i]==0)qmin.push(-i);
	p=0;
	while(!qmin.empty()){
		auto x=-qmin.top();
		qmin.pop();
		if(x!=A[p++]){
			cout<<"No"<<endl;
			return 0;
		}
		for(auto y:G[x])
			if(--ind[y]==0)qmin.push(-y);
	}

	cout<<"Yes"<<endl;
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans){
		cout<<x+1<<" "<<y+1<<endl;
	}
}
