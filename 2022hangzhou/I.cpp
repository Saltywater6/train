#include<bits/stdc++.h>
using namespace std;
int cur;
void walk(int x){
	cout<<"walk "<<x<<"\n";
	cout.flush();
	cin>>cur;
}
unordered_map<int,int>mp;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int S=0;
	for(int i=1;i<=1000;++i){
		walk(rand()%100000000);
		S=max(S,cur);
	}
	for(int i=1;i<=4500;++i){
		walk(1);
		if(mp.count(cur)){
			cout<<"guess "<<i-mp[cur]<<"\n";
			cout.flush();
			return 0;
		}
		mp[cur]=i;

	}
	walk(S);
	for(int i=0;i<4400;++i){
		if(mp.count(cur)){
			cout<<"guess "<<S+4500*i+4500-mp[cur]<<"\n";
			cout.flush();
			return 0;
		}
		walk(4500);
	}
}

