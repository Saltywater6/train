#include<bits/stdc++.h>
using namespace std;

const int M=5e5+10;

int n,T;
int nxt[M],hd[M],to[M],val[M],ecnt;
void Add(int a,int b,int c){
	nxt[++ecnt]=hd[a];
	to[hd[a]=ecnt]=b;
	val[ecnt]=c;
}
int ls[M<<5],rs[M<<5],s[M<<5],rt[M];
void ins(int &cur,int pre,int x,int v,int L=1,int R=T){
	static int tot;
	cur=++tot;
	ls[cur]=ls[pre],rs[cur]=rs[pre],s[cur]=s[pre];
	if(L==R){
		s[cur]=v;
		return ;
	}
	int mid=(L+R)>>1;
	if(x<=mid)ins(ls[cur],ls[pre],x,v,L,mid);
	else ins(rs[cur],rs[pre],x,v,mid+1,R);
}
int qry(int cur,int x,int L=1,int R=T){
	if(!cur)return 0;
	if(L==R)return s[cur];
	int mid=(L+R)>>1;
	if(x<=mid)return qry(ls[cur],x,L,mid);
	return qry(rs[cur],x,mid+1,R);
}
int A[M],dis[M];
struct node{
	int x,dis;
	bool operator <(const node &_)const{
		return dis>_.dis;
	}
};
priority_queue<node>que;
bool mk[M];
int main(){
	//freopen("hayasa","w",stdout);
	scanf("%d%d",&n,&T);
	for(int i=1;i<=T;++i){
		int m;
		scanf("%d",&m);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			Add(a,b,i),Add(b,a,i);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
		scanf("%d",&A[i]);
	for(int i=q;i;--i)
		ins(rt[i],rt[i+1],A[i],i);
	dis[1]=1;
	que.push((node){1,dis[1]});
	while(!que.empty()){
		int x=que.top().x;
		que.pop();
		if(mk[x])continue;
		mk[x]=1;
		//cout<<x<<" "<<dis[x]<<endl;
		for(int i=hd[x];i;i=nxt[i]){
			int y=to[i],v=val[i];
			int tmp=qry(rt[dis[x]],v);
			//cout<<x<<" "<<dis[x]<<" "<<y<<" "<<tmp<<" "<<v<<endl;
			if(tmp){
				if(!dis[y]||dis[y]>tmp+1){
					dis[y]=tmp+1;
					que.push((node){y,dis[y]});
				}
			}
		}
	}
	printf("%d",dis[n]?dis[n]-1:-1);
}
