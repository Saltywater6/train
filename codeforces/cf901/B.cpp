#include<bits/stdc++.h>
using namespace std;

void solve(){	
	int n,m,k;
	cin>>n>>m>>k;
	multiset<int>s1,s2;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		s1.insert(x);
	}
	for(int i=0;i<m;++i){
		int x;
		cin>>x;
		s2.insert(x);
	}
	int t=min(k,64);
	for(int i=0;i<t;++i){
		if(i%2==0){
			int t1=*s1.begin();
			int t2=*--s2.end();
			if(t2<t1)continue;
			s1.erase(s1.begin());
			s2.erase(--s2.end());
			s1.insert(t2);
			s2.insert(t1);
		}else{
			swap(s1,s2);
			int t1=*s1.begin();
			int t2=*--s2.end();
			if(t2<t1)continue;
			s1.erase(s1.begin());
			s2.erase(--s2.end());
			s1.insert(t2);
			s2.insert(t1);
			swap(s1,s2);
		}
	}
	k-=t;
	for(int i=0;i<k%16;++i){
		if(i%2==0){
			int t1=*s1.begin();
			int t2=*--s2.end();
			if(t2<t1)continue;
			s1.erase(s1.begin());
			s2.erase(--s2.end());
			s1.insert(t2);
			s2.insert(t1);
		}else{
			swap(s1,s2);
			int t1=*s1.begin();
			int t2=*--s2.end();
			if(t2<t1)continue;
			s1.erase(s1.begin());
			s2.erase(--s2.end());
			s1.insert(t2);
			s2.insert(t1);
			swap(s1,s2);
		}
	}
	long long sum=0;
	for(auto x:s1)sum+=x;
	cout<<sum<<"\n";

		
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
