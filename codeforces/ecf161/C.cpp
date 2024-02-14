#include<bits/stdc++.h>
using namespace std;

using ll = long long ;

const int M=1e5+10;
int pre[M][22],nxt[M][22];
void solve() {
	int n;
	cin>>n;
	vector<int >A(n);
	for(int i=0;i<n;++i)cin>>A[i];
	nxt[0][0]=1;
	for(int i=1;i<n-1;++i)
		if(abs(A[i]-A[i-1])>abs(A[i]-A[i+1]))
			nxt[i][0]=1;
		else nxt[i][0]=abs(A[i]-A[i+1]);
	pre[n-1][0]=1;
	for(int i=n-2;i;--i)
		if(abs(A[i]-A[i-1])<abs(A[i]-A[i+1]))
			pre[i][0]=1;
		else pre[i][0]=abs(A[i]-A[i-1]);

	for(int j=1;j<20;++j)
		for(int i=0;i<n;++i){
			if(i+(1<<j)<n)
				nxt[i][j]=nxt[i][j-1]+nxt[i+(1<<(j-1))][j-1];
			if(i-(1<<j)>=0)
				pre[i][j]=pre[i][j-1]+pre[i-(1<<(j-1))][j-1];
		}
	int m;
	cin>>m;
	for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;
		x--,y--;
		int ans=0;
		if(x<y){
			for(int i=19;i>=0;--i)
				if(x+(1<<i)<=y)
					ans+=nxt[x][i],x+=(1<<i);
		}
		if(x>y){
			for(int i=19;i>=0;--i)
				if(x-(1<<i)>=y)
					ans+=pre[x][i],x-=(1<<i);
		}
		cout<<ans<<"\n";
	}

}

int main() {
	cin.tie()->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--) solve();
	return  0;
}

