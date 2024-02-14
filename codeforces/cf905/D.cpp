#include<bits/stdc++.h>
using namespace std;

multiset<int>stl,str;
int main(){
	//freopen("hayasa","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int l,r;
		char op[10];
		scanf("%s%d%d",op,&l,&r);
		if(*op=='+'){
			stl.insert(l);
			str.insert(r);
		}else{
			stl.erase(stl.find(l));
			str.erase(str.find(r));
		}
		if(stl.size()>1&&*(--stl.end())>*str.begin())puts("Yes");
		else puts("No");
	}
}

	
