#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define Max(a,b) ((a)<(b))&&((a)=(b))
#define Min(a,b) ((a)>(b))&&((a)=(b))
const int M=1e6+5;
int T;
int A[1005],B[1005];
int pos[1005];
int S[M];
int que[M<<2];
bool mk[1005][1005];
int main() {
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; ++i)scanf("%d",&A[i]);
        for(int i=1; i<=n; ++i)scanf("%d",&B[i]),pos[B[i]]=i;
        for(int i=1; i<=n; ++i)
            A[i]=pos[A[i]];
        int cnt=0;
        int top=0;
		while(A[1]!=1){
			S[++top]=1;
			int t=A[1];
			for(int j=2;j<=n;j++)
				A[j-1]=A[j];
			A[n]=t;
		}
		while(A[2]!=n){
			S[++top]=2;
			int t=A[2];
			for(int j=3;j<=n;j++)
				A[j-1]=A[j];
			A[n]=t;
		}
        for(int i=1; i<=n; ++i)
            for(int j=i+1; j<=n; ++j)
                if(A[i]>A[j])mk[A[i]][A[j]]=true,cnt++;
        int L=1,R=0;
        for(int i=1; i<=n; ++i)que[++R]=A[i];
        while(cnt) {
            int a=que[L],b=que[L+1];
            if(mk[a][b])que[++R]=b,que[++R]=a,S[++top]=2,S[++top]=1,L+=2,cnt--,mk[a][b]=false;
            else que[++R]=a,S[++top]=1,L++;
        }
        while(que[L]!=1)++L,S[++top]=1;
        for(int i=1; i<=top; ++i)printf("%d",S[i]);
        puts("");
    }
    return 0;
}
