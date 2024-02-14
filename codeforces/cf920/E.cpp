#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

void solve(){
	int h,w,xa,ya,xb,yb;
	cin>>h>>w>>xa>>ya>>xb>>yb;
	if(xa>=xb){
		cout<<"Draw\n";
		return ;
	}
	if(xb-xa&1){
		if(ya<=yb){
			yb=min(yb+(xb-xa)/2,w);
			ya=min(ya+(xb-xa)/2+1,w);
			cout<<(ya>=yb?"Alice":"Draw")<<endl;
		}else {
			yb=max(yb-(xb-xa)/2,1);
			ya=max(ya-(xb-xa)/2-1,1);
			cout<<(ya<=yb?"Alice":"Draw")<<endl;
		}
	}else{
		if(ya<=yb){
			yb=max(yb-(xb-xa)/2,1);
			ya=max(ya-(xb-xa)/2,1);
			cout<<(ya>=yb?"Bob":"Draw")<<endl;
		}else {
			yb=min(yb+(xb-xa)/2,w);
			ya=min(ya+(xb-xa)/2,w);
			cout<<(ya<=yb?"Bob":"Draw")<<endl;
		}
	}


}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
}
