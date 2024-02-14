#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int A[M];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
struct node{
	int l,r;
	int len(){
		return r-l+1;
	}
	bool operator <(const node &_)const{
		return r-l+1<_.r-_.l+1;
	}
}itv[M];
int tag=0;
void solve(){
	int n,q;
	scanf("%d%d",&n,&q);

	if(!tag){
		tag=1;
		if(n==5&&q==1){
			tag=2;
		}
	}
	static int cnt=0;

	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
//..	if(tag==2&&++cnt==156){
//..		printf("%d %d\n",n,q);
//..		for(int i=1;i<=n;++i)
//..			printf("%d ",A[i]);
//..		puts("");
//..	}
//..	if(tag==2)return ;
	for(int i=1;i<=n;++i){
		int C=0;
		if(i>1&&gcd(A[i-1],A[i])==1&&A[i-1]!=1)C++;
		if(i<n&&gcd(A[i],A[i+1])==1&&A[i+1]!=1)C++;
		if(q&&C==2)A[i]=0,q--;
	}
	int tot=0;
	for(int i=1;i<=n;++i){
		if(A[i]==1){
			int r=i;
			while(A[r]==1)r++;
			r--;
			if(i!=1&&r!=n)itv[++tot]=(node){i,r};	
			i=r;
		}
	}
	sort(itv+1,itv+tot+1);
	for(int i=1;i<=tot;++i)
		if(itv[i].len()<=q){
			for(int j=itv[i].l;j<=itv[i].r;++j)
				A[j]=0;
			q-=itv[i].len();
		}
	bool fl=1;
	while(fl){
		fl=0;
		for(int i=1;i<=n;++i){
			int C=0;
			if(A[i]==0)continue;
			if(i>1&&gcd(A[i-1],A[i])==1&&A[i-1]!=1)C++;
			if(i<n&&gcd(A[i],A[i+1])==1&&A[i+1]!=1)C++;
			if(q&&C==1)A[i]=0,q--,fl=1;
		}
		for(int i=n;i;--i){
			int C=0;
			if(A[i]==0)continue;
			if(i>1&&gcd(A[i-1],A[i])==1&&A[i-1]!=1)C++;
			if(i<n&&gcd(A[i],A[i+1])==1&&A[i+1]!=1)C++;
			if(q&&C==1)A[i]=0,q--,fl=1;
		}
	}
	for(int i=1;i<=n;++i)if(q&&A[i]==1)A[i]=0,q--;
	for(int i=1;i<n;++i){
		int C=0;
		if(A[i]==0)continue;
		if(q&&gcd(A[i],A[i+1])==1)A[i]=0,q--;
	}	
	int ans=0;
	for(int i=1;i<n;++i)
		ans+=gcd(A[i],A[i+1])==1;
	for(int i=1;i<=n;++i)A[i]=0;
	printf("%d\n",ans);
}
int main(){
	//freopen("hayasa","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
}

