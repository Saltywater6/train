#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int deg[M];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            deg[a]++,deg[b]++;
        }   
        sort(deg+1,deg+n+1,greater<int>());
		long long sum=0;
        int mx=0,mn=0;
        for(int i=1;i<=n;++i){
            sum+=deg[i];
            if(sum-1ll*i*(i-1)==2ll*m-sum){
                mx=i;
                if(!mn)mn=i;
            }
        }
        int ans1=1,ans2=1;
        for(int i=mx+1;i<=n;++i)
            if(deg[i]==mx-1)ans1++;    
        for(int i=1;i<=mn;++i)
            if(deg[i]==mn)ans2++;
        printf("%d %d\n",ans1,ans2);
        for(int i=1;i<=n;++i)deg[i]=0;
    }
}

