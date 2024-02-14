#include<bits/stdc++.h>
using namespace std;

const int M=2005;


int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin>>n;
	int x1[M],x2[M],y1[M],y2[M],r[M];
	string c[M],s[M];
	for(int q=0;q<n;++q){
		cin>>s[q];
		if(s[q][2]=='r')
			cin>>x1[q]>>y1[q]>>r[q]>>c[q];
		if(s[q][2]=='c')
			cin>>x1[q]>>y1[q]>>x2[q]>>y2[q]>>c[q];
		if(s[q][2]=='n'){
			cin>>x1[q]>>y1[q]>>x2[q]>>y2[q];
			for(int j=y2[q];j>=y1[q];--j){
				for(int i=x1[q];i<=x2[q];++i){
					char ans='.';
					for(int k=0;k<q;++k){
						if(s[k][2]=='r'){
							if(1ll*(i-x1[k])*(i-x1[k])+1ll*(j-y1[k])*(j-y1[k])<=1ll*r[k]*r[k])
								ans=c[k][0];
						}
						if(s[k][2]=='c'){
							if(i>=x1[k]&&i<=x2[k]&&j>=y1[k]&&j<=y2[k])
								ans=c[k][0];
						}
					}
					cout<<ans;

				}
				cout<<"\n";
			}
		}
	}
}
