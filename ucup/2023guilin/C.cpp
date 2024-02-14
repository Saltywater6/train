#include<bits/stdc++.h>
using namespace std;


const int mod=998244353;
int pw[200005],cnt[200005];
struct Linear{
	int A[50],size;

	void ins(int x){
		for(int i=20;i>=0;--i){
			if(x>>i&1){
				if(!A[i]){
					A[i]=x,size++;
					return ;
				}
				else x^=A[i];
			}
		}
	}
	void clear(){
		for(int i=0;i<=20;++i)
			A[i]=0;
		size=0;
	}

}lin;
int calc(int n){
	if(n==1)return pw[cnt[n]-1];
	int s=cnt[n]-1;
	lin.clear();
	if(cnt[1])lin.ins(1),s+=cnt[1];
	for(int i=2;i*i<=n;++i){
		if(n%i)continue;
		if(cnt[i])lin.ins(i),s+=cnt[i];
		if(i*i!=n&&cnt[n/i])lin.ins(n/i),s+=cnt[n/i];
	}
	return pw[s-lin.size];
}
void solve(){
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		cnt[x]++;
	}
	lin.clear();
	for(int i=1;i<=n;++i)
		if(cnt[i])lin.ins(i);
	long long ans=pw[n-lin.size]-1;
	for(int i=1;i<=n;++i)
		if(cnt[i]){
			ans+=calc(i);
		}
	cout<<ans%mod<<"\n";
	for(int i=1;i<=n;++i)cnt[i]=0;

}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	//freopen("hayasa","r",stdin);
	pw[0]=1;
	for(int i=1;i<=2e5;++i)pw[i]=(pw[i-1]<<1)%mod;
	int T;
	cin>>T;
	while(T--)solve();
}

