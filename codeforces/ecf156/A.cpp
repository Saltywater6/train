#include<bits/stdc++.h>
using namespace std;

void solve(){
	int px,py,ax,ay,bx,by;
	cin>>px>>py>>ax>>ay>>bx>>by;
	double r1=sqrt(ax*ax+ay*ay);
	double r2=sqrt(bx*bx+by*by);
	double r3=sqrt((ax-px)*(ax-px)+(ay-py)*(ay-py));
	double r4=sqrt((bx-px)*(bx-px)+(by-py)*(by-py));
	double r5=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))/2;
	double ans=min(max(r1,r3),min(max(r2,r4),max(min(r1,r2),max(min(r3,r4),r5))));
	printf("%.9f\n",ans);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
