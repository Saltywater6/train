#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long ;

int ask(int x){
	cout<<"? "<<x+1<<endl;
	cout.flush();
	char c;
	cin>>c;
	if(c=='>')return 1;
	if(c=='<')return -1;
	return 0;
}
void solve(){
	int n;
	cin>>n;
	int x=0;
	vector<int>ans(n),A(n),B(n);
	for(int i=0;i<n;++i)A[i]=i;
	auto get=[&](auto self,int l,int r)->void{
		if(l>r)return ;
		int mid=rand()%(r-l+1)+l;
		int tmp;
		while((tmp=ask(A[mid]))&&tmp!=0)x+=tmp;
		ans[A[mid]]=x;
		int tl=l,tr=r;
		for(int i=l;i<=r;++i){
			if(i!=mid){
				tmp=ask(A[i]);
				ask(A[mid]);
				if(tmp<0)B[tl++]=A[i];
				else B[tr--]=A[i];
			}
		}
		B[tl]=mid;
		for(int i=l;i<=r;++i)A[i]=B[i];
		self (self ,l,tl-1),self ( self ,tr+1,r);
	};
	get(get,0,n-1);
	int mn=0;
	for(int i=0;i<n;++i)
		mn=min(mn,ans[i]);

	cout<<"! ";
	for(int i=0;i<n;++i){
		cout<<ans[i]-mn+1<<" ";
	}
	cout<<endl;
	cout.flush();
	
}
int main(){
	srand(114514);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
