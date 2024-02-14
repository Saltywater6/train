#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
using ll=long long ;
const int M=1e6+10;
const ll bas1=233,bas2=269;
const int P1=1e9+7,P2=1e9+9;
int h[2][2][M],pw1[M],pw2[M];
pii hash1(int l,int r){
	return make_pair(((h[0][0][r]-1ll*h[0][0][l-1]*pw1[r-l+1]%P1)%P1+P1)%P1,
			((h[0][1][r]-1ll*h[0][1][l-1]*pw2[r-l+1]%P2)%P2+P2)%P2);
}
pii hash2(int l,int r){
	return make_pair(((h[1][0][l]-1ll*h[1][0][r+1]*pw1[r-l+1]%P1)%P1+P1)%P1,
			((h[1][1][l]-1ll*h[1][1][r+1]*pw2[r-l+1]%P2)%P2+P2)%P2);
}
bool check(int l1,int r1,int l2,int r2){
	return hash1(l1,r1)==hash2(l2,r2);
}
bool chk2(int l1,int r1,int l2,int r2){
	return hash1(l1,r1)==hash1(l2,r2);
}
int n;
struct Seg{
	vector<int>G[M<<2];
	void build(int L=1,int R=n,int p=1){
		G[p].push_back(0);
		G[p].push_back(1e9);
		sort(G[p].begin(),G[p].end());
		if(L==R)return ;
		int mid=(L+R)>>1;
		build(L,mid,p<<1);
		build(mid+1,R,p<<1|1);
	}
	void upd(int l,int r,int v,int L=1,int R=n,int p=1){
		if(L==l&&r==R){
			G[p].push_back(v);
			return ;
		}
		int mid=(L+R)>>1;
		if(r<=mid)upd(l,r,v,L,mid,p<<1);
		else if(l>mid)upd(l,r,v,mid+1,R,p<<1|1);
		else {
			upd(l,mid,v,L,mid,p<<1);
			upd(mid+1,r,v,mid+1,R,p<<1|1);
		}
	}
	int qry_mn(int x,int v,int L=1,int R=n,int p=1){
		if(L==R)return *(lower_bound(G[p].begin(),G[p].end(),v));
		int mid=(L+R)>>1,res=*(lower_bound(G[p].begin(),G[p].end(),v));
		if(x<=mid)return min(res,qry_mn(x,v,L,mid,p<<1));
		return min(res,qry_mn(x,v,mid+1,R,p<<1|1));
	}
	int qry_mx(int x,int v,int L=1,int R=n,int p=1){
		if(L==R)return *--upper_bound(G[p].begin(),G[p].end(),v);
		int mid=(L+R)>>1;
		int res=*--upper_bound(G[p].begin(),G[p].end(),v);
		if(x<=mid)return max(res,qry_mx(x,v,L,mid,p<<1));
		return max(res,qry_mx(x,v,mid+1,R,p<<1|1));
	}
}Tr1,Tr2;
char ss[M],s[M];
void init(){
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw1[i]=pw1[i-1]*bas1%P1;
		pw2[i]=pw2[i-1]*bas2%P2;
	}
}
int main(){
	//freopen("hayasa","r",stdin);
	scanf("%d%s",&n,ss+1);
	for(int i=1;i<=n;++i){
		s[2*i-1]=ss[i];
		s[2*i]='#';
	}
	n=n*2;
	for(int i=1;i<=n;++i){
		h[0][0][i]=(h[0][0][i-1]*bas1+s[i])%P1;
		h[0][1][i]=(h[0][1][i-1]*bas2+s[i])%P2;
	}
	for(int i=n;i;--i){
		h[1][0][i]=(h[1][0][i+1]*bas1+s[i])%P1;
		h[1][1][i]=(h[1][1][i+1]*bas2+s[i])%P2;
	}
	init();
	for(int i=1;i<=n;++i){
		int l=1,r=min(n-i+1,i);
		int res=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i-mid+1,i+mid-1,i-mid+1,i+mid-1)){
				l=mid+1,res=mid;
			}else r=mid-1;
		}
		Tr1.upd(i-res+1,i,i);
		Tr2.upd(i,i+res-1,i);
	}
	Tr1.build(),Tr2.build();
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		l=l*2-1,r=r*2-1;
		if(check(l,r,l,r)){
			puts("0 0");
		}else{
			int L=1,R=(r-l+1)/2,res=0;
			while(L<=R){
				int mid=(L+R)>>1;
				if(check(l,l+mid-1,r-mid+1,r)){
					L=mid+1,res=mid;
				}else R=mid-1;
			}
			int l1=(Tr1.qry_mx(l+res,(l+r)>>1)-(l+res)+1)*2-1;
			int ans1=(res*2+l1+1)/2;
			L=1,R=res;
			int t1=0;
			while(L<=R){
				int mid=(L+R)>>1;
				if(chk2(l+res+l1,l+res+l1+mid-1,r-res+1,r-res+1+mid-1)){
					L=mid+1,t1=mid;
				}else R=mid-1;
			}
			int ans2=t1/2+1;
			int l2=(r-res-Tr2.qry_mn(r-res,((l+r+1)>>1))+1)*2-1;

			int ans3=(res*2+l2+1)/2;
			L=1,R=res;
			int t2=0;
			while(L<=R){
				int mid=(L+R)>>1;
				if(chk2(l+res-mid,l+res-1,r-res-l2-mid+1,r-res-l2)){
					L=mid+1,t2=mid;
				}else R=mid-1;
			}
			//cout<<t2<<endl;
			int ans4=t2/2+1;
			r=(r+1)/2;
			l=(l+1)/2;
			if(ans1>ans3){
				printf("%d %d\n",r-l+1-ans1,ans2);
			}else if(ans1==ans3){
				printf("%d %d\n",r-l+1-ans1,ans2+ans4);
			}else printf("%d %d\n",r-l+1-ans3,ans4);
		}
	}
	return 0;
}
				
			

