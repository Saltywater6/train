#include<bits/stdc++.h>
using namespace std;

const int M=66;
int f[M][2],A[M],s;
//l1: x<=n   l2: l<=x   l3: r<=x  l4:l+r<x
int dp(int x,int l1,int l2,int l3,int l4,int pre){
	if(x==0)return 1;
	cout<<x<<" "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<pre<<endl;
	if(!l1&&!l2&&!l3&&l4&&f[x][pre]!=-1)return f[x][pre];
	int mx=l1?A[x]:0,res=0;
	for(int t=0;t<=mx;++t)
		for(int l=0;l<=mx;++l)
			for(int r=0;r<=mx;++r){
				if(l^r^t^(s>>x&1))continue;
				if(l4&&l+r>=pre*2+t)continue;
				if(l3&&r>t)continue;
				if(l2&&l>t)continue;
				res+=dp(x-1,l1&&t==mx,l2&&l==t,l3&&r==t,l4&&(l+r)==pre*2+t,t);
			}
	if(!l1&&!l2&&!l3&&!l4)f[x][pre]=res;
	return res;
}
int calc(int n){
	int cnt=0;
	memset(f,-1,sizeof f);
	while(n)A[++cnt]=n&1,n>>=1;
	return dp(cnt,1,1,1,1,0);
}
void solve(){
	int n,m;
	cin>>n>>m;
	s=m;
	if(n%4==0)s^=n;
	if(n%4==1)s^=1;
	if(n%4==2)s^=n+1;
	if(n==0){
		cout<<"0\n";
		return ;
	}
	cout<<(calc(n)+calc(m)-calc(m-1))<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)solve();
}



