#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
struct node{
	int x,y;
	node(int a,int b){
		x=a,y=b;
	}
	bool operator <(const node &_)const{
		return x<_.x;
	}
};
bool inc(node a,node b,node c){
	return 1.0*(b.y-a.y)*(c.x-b.x)<=1.0*(c.y-b.y)*(b.x-a.x);
}

bool dec(node a,node b,node c){
	return 1.0*(b.y-a.y)*(c.x-b.x)>=1.0*(c.y-b.y)*(b.x-a.x);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	vector<node>A;
	vector<int>col(n);
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		A.emplace_back(x,y);	
	}
	sort(A.begin(),A.end());
	vector<int >up,down;
	for(int i=0;i<n;++i){
		while(up.size()>=2&&inc(A[up[up.size()-2]],A[up.back()],A[i]))
			up.pop_back();
		up.push_back(i);
	}
	for(int i=0;i<n;++i){
		while(down.size()>=2&&dec(A[down[down.size()-2]],A[down.back()],A[i]))
			down.pop_back();
		down.push_back(i);
	}
	for(auto x:up)col[x]=1;
	for(auto x:down)col[x]=1;
	int ans=1;
	auto angle=[&](int i,int j)->double{
		if(A[j].x>A[i].x)return atan(1.0*(A[j].y-A[i].y)/(A[j].x-A[i].x));
		if(A[j].x==A[i].x){
			if(A[j].y>A[i].y)return acos(-1)/2;
			return -acos(-1)/2;
		}
		if(A[j].x<A[i].x){
			return atan(1.0*(A[j].y-A[i].y)/(A[j].x-A[i].x))+acos(-1);
		}
	};
	for(int i=0;i<n;++i)if(col[i]==0){
		//cout<<A[i].x<<" "<<A[i].y<<endl;
		vector<pair<double,int>>tmp;
		for(int j=0;j<n;++j)
			if(j!=i)tmp.emplace_back(angle(i,j),col[j]);
		sort(tmp.begin(),tmp.end());
		for(int j=1;j<(int)tmp.size();++j)
			if(tmp[j].second&&tmp[j-1].second)ans++;
		if(tmp.back().second&&tmp[0].second)ans++;
	}
	cout<<ans<<endl;
}

