#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
const double eps=1e-8;
int n;
int a[M];
double ans[M],sum;
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)scanf("%d",&a[i]),sum+=a[i];
    sum/=(n+1);
    for(int i=1; i<=n; ++i) {
        if(i==1)ans[i]=sum*2;
        else ans[i]=sum;
        printf("%.8f ",ans[i]);
    }    
    return 0;
}
