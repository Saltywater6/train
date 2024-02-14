#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int T;
int a[M];
vector<int>Q[M];
int L[M],R[M];
bool f;
void dfs(int now) {
    if(!f)return;
    if(Q[now].size()==0) {
        if(a[now]!=-1)L[now]=R[now]=a[now];
        return;
    }
    int mxl=-1e9,mxr=-1e9,cntl=0,cntr=0;
    bool Have=false;
    for(int i=0; i<Q[now].size(); ++i) {
        int To=Q[now][i];
        dfs(To);
        if(L[To]>mxl)mxl=L[To],cntl=0;
        else if(L[To]==mxl)cntl++;
        if(R[To]>mxr)mxr=R[To],cntr=0;
        else if(R[To]==mxr)cntr++;
        if(R[To]==-1)Have=true;
    }
    if(cntl>0)mxl++;
    if(cntr>0)mxr++;
    if(Have)mxr=-1;
    if(~a[now]) {
        if(mxl<=a[now]&&(a[now]<=mxr||mxr==-1))L[now]=R[now]=a[now];
        else f=false;
    }else L[now]=mxl,R[now]=mxr;
}
int main() {
	//freopen("hayasa","r",stdin);
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; ++i)L[i]=0,R[i]=-1,Q[i].clear();
        for(int i=1; i<=n; ++i)scanf("%d",&a[i]);
        for(int i=1; i<n; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            Q[u].push_back(v);
        }
        f=true;
        dfs(1);
        if(f)puts("Reasonable");
        else puts("Unreasonable");
    }
    return 0;
}
