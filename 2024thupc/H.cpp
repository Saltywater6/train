#include<bits/stdc++.h>
using namespace std;

const int M=(1<<20)+10;
struct BIT{
	int f[M];
	void upd(int x,int v){
		while(x<M)f[x]+=v,x+=x&-x;
	}
	int qry(int x){
		int res=0;
		while(x)res+=f[x],x-=x&-x;
		return res;
	}
}Tr;

bool fl;
char str[M];	
int len[M],nxt[M],pre[M],n;

int getnxt(int x){
	return nxt[x]==x?x:nxt[x]=getnxt(nxt[x]);
}
int getpre(int x){
	return pre[x]==x?x:pre[x]=getpre(pre[x]);
}
set<int>s[M];
void rebuild(int op){
	int cnt=0,now=0;
	static int j=0;
	while(len[j]<op)s[j++].clear();
	for(int i=n;i;--i){
		if(pre[i]==i){
			cnt++;
			now=now>>1;
			if(str[i])now+=1<<(op-1);
			if(cnt>=op&&len[now]==op)
				s[now].insert(i);
		}
	}
}


int main(){
	//freopen("10.in","r",stdin);
	//freopen("my.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>str;
	for(int i=n;i;--i)str[i]=str[i-1]-'0';
	for(int i=1;i<=n;++i)len[i]=len[i>>1]+1;
	for(int i=1;i<=n+1;++i)nxt[i]=pre[i]=i;
	for(int i=1;i<=n;++i)Tr.upd(i,1);
	for(int i=1;i<=n;++i){
		if(len[i]!=len[i-1])rebuild(len[i]);
		if(!s[i].empty()){
			int l=*s[i].begin(),r=l;
			for(int c=1;c<len[i];++c)r=getnxt(r+1);
			cout<<Tr.qry(l)<<" "<<s[i].size()<<"\n";
			//erase
			int now=i;
			s[now].erase(l);
			for(int c=1,tl=getnxt(l+1),tr=getnxt(r+1);c<len[i]&&tr<=n;++c,tl=getnxt(tl+1),tr=getnxt(tr+1)){
				now=now<<1&((1<<len[i])-1);
				if(str[tr])now|=1;
				if(len[now]==len[i])s[now].erase(tl);
			}
			now=i;
			for(int c=1,j=getpre(l-1);c<len[i]&&j;++c,j=getpre(j-1)){
				now=now>>1;
				if(str[j])now|=1<<(len[i]-1);
				if(len[now]==len[i])s[now].erase(j);
			}

			for(int c=0,j=l;c<len[i];++c,j=getnxt(j+1)){
				pre[j]=j-1,nxt[j]=j+1,Tr.upd(j,-1);
			}

			//insert
			int t=l;
			for(int c=1;c<len[i]&&getpre(l-1)>0;c++,l=getpre(l-1));
			r=l;

			now=0;
			for(int c=1;c<len[i]&&r<=n;++c,r=getnxt(r+1)){
				now=now<<1&((1<<len[i])-1);
				if(str[r])now|=1;
			}

			for(int c=1;c<len[i]&&r<=n&&l<t;++c,r=getnxt(r+1),l=getnxt(l+1)){
				now=now<<1&((1<<len[i])-1);
				if(str[r])now|=1;
				if(len[now]==len[i])s[now].insert(l);
			}
		}else cout<<"-1 0\n";
	}
}
