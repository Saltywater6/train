#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	set<string>st;
	while(T--){
		int n,fl=0;
		cin>>n;
		while(n--){
			string s;
			cin>>s;
			if(st.find(s)!=st.end())continue;
			else if(s.find("bie")<s.length()){
				st.insert(s),fl=1;
				cout<<s<<"\n";
			}
		}
		if(!fl)cout<<"Time to play Genshin Impact, Teacher Rice!\n";
	}
}
