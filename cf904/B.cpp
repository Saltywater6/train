#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
char s[M];
void solve(){
	int n;
	cin>>n>>s;
	reverse(s,s+n);
	long long ans=0;
	int t=0;
	for(int i=0;i<n;++i){
		if(s[i]=='0')
			cout<<ans<<" ";
		else{
			t=max(t,i);
			while(t<n&&s[t]=='1')t++;
			if(t==n){
				for(int j=i;j<n;++j)
					cout<<"-1 ";
				break;
			}else{
				ans+=t-i,swap(s[t],s[i]);
				cout<<ans<<" ";
			}
		}
	}
	cout<<"\n";
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
}
