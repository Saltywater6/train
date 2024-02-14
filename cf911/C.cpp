#include<bits/stdc++.h>
using namespace std;

const int M=3e5+10;
string s;
int ch[M][2];
int dfs(int x){
	if(ch[x][0]==-1&&ch[x][1]==-1)return 0;
	int tmp=1e9;
	if(ch[x][0]!=-1)tmp=min(tmp,dfs(ch[x][0])+1-(s[x]=='L'));
	if(ch[x][1]!=-1)tmp=min(tmp,dfs(ch[x][1])+1-(s[x]=='R'));
	return tmp;
}
void solve(){
	int n;
	cin>>n>>s;
	for(int i=0;i<n;++i){
		int a,b;
		cin>>a>>b;
		--a,--b;
		ch[i][0]=a,ch[i][1]=b;
	}
	//cout<<ch[0][0]<<" "<<ch[0][1]<<endl;
	cout<<dfs(0)<<"\n";
}
int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
}

