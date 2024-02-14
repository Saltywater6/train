#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
void solve();
int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--)solve();
}

const int N=3e5+3;
int a[N],b[N],c[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int l=1,r=1e9+1,mid,ans;
	while(r>=l){
		int mid=l+r>>1;
		int mn=0,s=0,k=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=mid)k++;
			if(a[i]>=mid&&b[i]>=mid||a[i]<mid&&b[i]<mid)c[i]=0;
			if(a[i]>=mid&&b[i]<mid)c[i]=-1;
			if(a[i]<mid&&b[i]>=mid)c[i]=1;
			c[i]+=c[i-1];
			// cout<<"! "<<mid<<" "<<i<<" "<<c[i]<<endl;
			mn=min(mn,c[i]);
			s=max(s,c[i]-mn);
		}
		if(k+s>=n/2+1)ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
}
