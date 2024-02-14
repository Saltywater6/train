#include<bits/stdc++.h>
using namespace std;

int n,l,r;
double p;
double Pow(double a,int b){
	double res=1;
	for(;b;b>>=1,a=a*a)
		if(b&1)res=res*a;
	return res;
}
constexpr double eps=1e-6;
double solve(int n){
	double ans=0;
	for(int i=1;i<=n&&i<=1000;++i)
		for(int j=0;i+j<=n&&j<=1000;++j)
			ans+=Pow(p,i)*Pow((1-p)*i,j);
	return ans;
}

int main(){
	cin>>n>>p>>l>>r;
	printf("%.6f",(r-l+1)*p);
}
