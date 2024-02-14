#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
int n,m;
char s[2*M],t[M];
long long sums[M],sumt[M],f[M],g[M];
int z[M<<1],fail[M];
struct Seg{
	int s[M<<2];
	void build(int l,int r,int p){
		if(l==r){
			s[p]=l+z[l+n]-1;
			return ;
		}
		int mid=(l+r)>>1;
		build(l,mid,p<<1);
		build(mid+1,r,p<<1|1);
		s[p]=max(s[p<<1],s[p<<1|1]);
	}
	int qry(int l,int r,int v,int L,int R,int p){
		if(s[p]<v)return 0;
		if(L==R)return L;
		int mid=(L+R)>>1;
		if(r<=mid)return qry(l,r,v,L,mid,p<<1);
		else if(l>mid)return qry(l,r,v,mid+1,R,p<<1|1);
		int res=qry(l,mid,v,L,mid,p<<1);
		if(res)return res;
		return qry(mid+1,r,v,mid+1,R,p<<1|1);
	}
}Tr;
int main(){
	//freopen("hayasa","r",stdin);
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	strcat(s+1,t+1);
	for(int i=2,l=1,r=1;i<=2*n;++i){
		if(i<=r)z[i]=min(r-i+1,z[i-l+1]);
		while(i+z[i]<=2*n&&s[i+z[i]]==s[z[i]+1])++z[i];
		if(i+z[i]-1>r)r=i+z[i]-1,l=i;
	}
	for(int i=2,j=0;i<=n;++i){
		while(j&&s[j+1]!=s[i])j=fail[j];
		if(s[j+1]==s[i])++j;
		fail[i]=j;
	}
	for(int i=1;i<=n;++i){
		int w;
		scanf("%d",&w);
		f[i]=w+f[fail[i]];
		g[i]=g[i-1]+w;
	}
	for(int i=1;i<=n;++i){
		sums[i]=sums[i-1]+f[i];
		sumt[i]=sumt[i-1]+g[z[i+n]];
	}
	Tr.build(1,n,1);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		int t=Tr.qry(l,r,r,1,n,1);
		long long ans=0;
		if(t)ans=sumt[t-1]-sumt[l-1]+sums[r-t+1];
		else ans=sumt[r]-sumt[l-1];
		printf("%lld\n",ans);
	}
	return 0;
}
		


