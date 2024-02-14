#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	int x;
	set<int>T;
	for(int i=0;i<n;++i){
		cin>>x;
		if(x==1)T.insert(i);
	}
	while(q--){
		int op,x,y;
		cin>>op>>x;
		if(op==1){
			if(n*2-T.size()<x){
				cout<<"No\n";
			}else if((n*2-T.size()-x)%2==0){
				cout<<"Yes\n";
			}else {
				if(!T.empty()){
					int s1=*T.rbegin()*2-T.size()+1;
					int s2=2*(n-*T.begin()-1)-T.size()+1;
					cout<<(x<=max(s1,s2)?"Yes":"No")<<"\n";
				}else cout<<"No\n";
			}
		}else{
			--x,cin>>y;
			T.erase(x);
			if(y==1)T.insert(x);
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}
