#include<bits/stdc++.h>
using namespace std;

const int  M=3e5+10;
int A[M],stk[M],top;
int f[22][M],lim[22][M];
int st[22][M],n,lg[M];
void build(){
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i)st[0][i]=A[i];
	for(int j=1;j<=20;++j)
		for(int i=1;i<=n;++i)
			if(i+(1<<j-1)<=n)
				st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			else st[j][i]=st[j-1][i];
}
int qry(int l,int r){
	int t=lg[r-l+1];
	return min(st[t][l],st[t][r-(1<<t)+1]);
}
int main(){
	//freopen("hayasa","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	build();
	stk[0]=n+1;
	f[0][n+1]=n+1;
	for(int i=n;i;--i){
		while(top&&A[stk[top]]<A[i])top--;
		f[0][i]=stk[top];
		int L=stk[top],R=n;
		while(L<=R){
			int mid=(L+R)>>1;
			if(qry(stk[top],mid)>A[i]){
				L=mid+1,lim[0][i]=mid;
			}else R=mid-1;	
		}
		stk[++top]=i;
	}
//	for(int i=1;i<=n;++i)printf("%d ",lim[0][i]);
//	puts("");
	for(int j=1;j<=20;++j)
		for(int i=1;i<=n+1;++i){
			f[j][i]=f[j-1][f[j-1][i]];
			lim[j][i]=max(lim[j-1][i],lim[j-1][f[j-1][i]]);
		}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int t=l,res=0;
		for(int i=20;i>=0;--i)
			if(f[i][t]<=r){
				res=max(res,lim[i][t]);
				t=f[i][t];
			}
		puts(res>=r?"Yes":"No");
	}
}
