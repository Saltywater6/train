#include <bits/stdc++.h>
using namespace std;
const int M=3005;
int D1[M][M],D2[M][M],w[M][M];
int n,k;
int p[M];
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        for(int j=1;j<=p[i];j++)cin>>w[i][j];
    }
    for(int i=1;i<=k;i++)D1[0][i]=-1e9,D2[n+1][i]=-1e9;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++)D1[i][j]=D1[i-1][j];
        for(int j=p[i];j<=k;j++)D1[i][j]=max(D1[i][j],D1[i-1][j-p[i]]+w[i][p[i]]);
    }
    for(int i=n;i>=1;i--){
        for(int j=0;j<=k;j++)D2[i][j]=D2[i+1][j];
        for(int j=p[i];j<=k;j++)D2[i][j]=max(D2[i][j],D2[i+1][j-p[i]]+w[i][p[i]]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<p[i];j++){
            int sum=k-j;
            for(int p=0;p<=sum;p++)ans=max(ans,D1[i-1][p]+D2[i+1][sum-p]+w[i][j]);
        }
    }
    for(int i=1;i<=k;i++)ans=max(ans,D1[n][i]);
    printf("%d\n",ans);
    return 0;
}
