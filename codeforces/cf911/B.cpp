#include<bits/stdc++.h>
using namespace std;

int f[205][205][205][3];
void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<(f[a][b][c][0]?"1":"0")<<" ";
	cout<<(f[a][b][c][1]?"1":"0")<<" ";
	cout<<(f[a][b][c][2]?"1":"0")<<"\n";
}
int main(){
	//freopen("hayasa","r",stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	for(int i=1;i<=200;++i)
		f[i][0][0][0]=f[0][i][0][1]=f[0][0][i][2]=1;
	for(int i=1;i<=600;++i)
		for(int j=0;j<=i;++j)
			for(int k=0;k+j<=i;++k){
				int a=i-j-k,b=j,c=k;
				if(a>200||b>200||c>200)continue;
				for(int l=0;l<3;++l)
					if(f[a][b][c][l]){
						if(c)f[a+1][b+1][c-1][l]=1;
						if(b)f[a+1][b-1][c+1][l]=1;
						if(a)f[a-1][b+1][c+1][l]=1;
					}
			}

	while(T--)solve();
}

