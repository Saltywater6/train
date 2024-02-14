#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int ans=0;
	for(int i=0;i<n;++i){
		if(s[i]=='.'){
			int j=i;
			while(j<n&&s[j]=='.')j++;
			j--;
			if(j-i+1>2){
				cout<<"2\n";
				return ;
			}else ans+=j-i+1;
			i=j;
		}
	}
	cout<<ans<<endl;
}

int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}

