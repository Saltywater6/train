#include<bits/stdc++.h>

using namespace std;

const int M=1e5+10,P=256;
int A[M],B[M],tag[M],v[M];
char op[10];
bool fl[M][256];
int n;
void solve(){
	int i=1,cur=0;
	while(i<=n){
		if(fl[i][cur]){
			puts("No");
			return ;
		}
		fl[i][cur]=1;
		if(tag[i]==0){
			cur+=A[i];
			cur%=256;
			i++;
		}
		else if(tag[i]==1){
			if(cur==A[i])
				i=B[i];
			else i++;
		}
		else if(tag[i]==2){
			if(cur!=A[i])
				i=B[i];
			else i++;
		}
		else if(tag[i]==3){
			if(cur<A[i])
				i=B[i];
			else i++;
		}
		else if(tag[i]==4){
			if(cur>A[i])
				i=B[i];
			else i++;
		}

	}
	puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			memset(fl[i],0,sizeof fl[i]);
			scanf("%s",op);
			if(*op=='a'){
				scanf("%d",&A[i]);
				tag[i]=0;
			}else if(op[1]=='e'){
				tag[i]=1;
				scanf("%d%d",&A[i],&B[i]);
			}else if(op[1]=='n'){
				tag[i]=2;
				scanf("%d%d",&A[i],&B[i]);
			}else if(op[1]=='l'){
				scanf("%d%d",&A[i],&B[i]);
				tag[i]=3;
			}else{
				scanf("%d%d",&A[i],&B[i]);
				tag[i]=4;
			}
		}
		solve();
	}
}

