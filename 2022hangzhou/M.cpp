#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ls p<<1
#define rs p<<1|1
const int M=1e6+5;
int n,k;
int c[M],Tot;
int hd[M],to[M<<1],nx[M<<1],val[M<<1];
void add(int u,int v,int w) {
    nx[++Tot]=hd[u];
    to[Tot]=v;val[Tot]=w;
    hd[u]=Tot;
}
int L[M],R[M],lt[M],tot;
void dfs(int now,int Fa) {
    L[now]=++tot;lt[tot]=now;
    for(int i=hd[now]; i; i=nx[i]) {
        int To=to[i];
        if(To==Fa)continue;
        dfs(To,now);
    }
    R[now]=tot;
}
int A[M];
LL dis[M],ans;
void redfs(int now,int Fa) {
    for(int i=hd[now]; i ;i=nx[i]) {
        int To=to[i];
        if(To==Fa)continue;
        dis[To]=dis[now]+val[i];
        redfs(To,now);
    }
}
LL gcd(LL a,LL b) {
    if(!b)return a;
    return gcd(b,a%b);
}
struct SEG {
    LL W[M<<2];
    void update(int p,int l,int r,int pos,LL D) {
        if(l==r) {
            W[p]+=D;
            return;
        }
        int mid=l+r>>1;
        if(pos<=mid)update(ls,l,mid,pos,D);
        else update(rs,mid+1,r,pos,D);
        W[p]=gcd(abs(W[ls]),abs(W[rs]));
    }
}T;
LL sum;
void ddfs(int now,int Fa,int w) {
    if(now!=1) {
        int lx=lower_bound(A+1,A+k+1,L[now])-A;
        int rx=upper_bound(A+1,A+k+1,R[now])-A-1;
        if(lx<=rx) {
            T.update(1,1,k,lx,-w);
            if(rx<k)T.update(1,1,k,rx+1,w);
        }
        if(lx>1) {
            T.update(1,1,k,1,w);
            if(lx<=k)T.update(1,1,k,lx,-w);
        }
        if(rx<k) {
            T.update(1,1,k,rx+1,w);
        }
        sum+=1LL*((k-rx+lx-1)-(rx-lx+1))*w;
        ans=min(ans,sum/T.W[1]);
    }
    for(int i=hd[now]; i; i=nx[i]) {
        int To=to[i];
        if(To==Fa)continue;
        ddfs(To,now,val[i]);
    }
    if(now!=1) {
        int lx=lower_bound(A+1,A+k+1,L[now])-A;
        int rx=upper_bound(A+1,A+k+1,R[now])-A-1;
        if(lx<=rx) {
            T.update(1,1,k,lx,w);
            if(rx<k)T.update(1,1,k,rx+1,-w);
        }
        if(lx>1) {
            T.update(1,1,k,1,-w);
            if(lx<=k)T.update(1,1,k,lx,w);
        }
        if(rx<k) {
            T.update(1,1,k,rx+1,-w);
        }
        sum-=1LL*((k-rx+lx-1)-(rx-lx+1))*w;
    }
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1; i<=k; ++i)scanf("%d",&c[i]);
    for(int i=1; i<n; ++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    if(k==1) {
        printf("0");
        return 0;
    }
    dfs(1,0);
    for(int i=1; i<=k; ++i)A[i]=L[c[i]];
    sort(A+1,A+k+1);
    redfs(1,0);
    for(int i=1; i<=k; ++i) {
        sum+=dis[lt[A[i]]];
        T.update(1,1,k,i,dis[lt[A[i]]]-dis[lt[A[i-1]]]);
    }
    ans=sum/T.W[1];
    ddfs(1,0,0);
    printf("%lld",ans*2);
    return 0;
}
