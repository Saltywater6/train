#include<bits/stdc++.h>
using namespace std;

bool check(int n,int k){
	int s=0;
	while(n)s+=n%10,n/=10;
	return s%k==0;
}
void solve(){
	int n,k;
	cin>>n>>k;
	while(!check(n,k))n++;
	cout<<n<<"\n";
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	int T;
	cin>>T;
	while(T--)solve();
}
