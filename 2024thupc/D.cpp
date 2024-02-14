#include<bits/stdc++.h>
using namespace std;

char trans[1000];
namespace pam {
	const int maxn=100000;
	int sz, tot, last;
	int cnt[maxn], ch[maxn][26], len[maxn], fail[maxn][22];
	char s[maxn];
	int node(int l) {  // 建立一个新节点，长度为 l
		sz++;
		memset(ch[sz], 0, sizeof(ch[sz]));
		len[sz] = l;
		fail[sz] [0]= cnt[sz] = 0;
		return sz;
	}

	void clear() {  // 初始化
		sz = -1;
		last = 0;
		s[tot = 0] = '$';
		node(0);
		node(-1);
		fail[0][0] = 1;
	}

	int getfail(int x) {  // 找后缀回文
		while (len[x]!=-1&&s[tot - len[x] - 1] != trans[s[tot]]) x = fail[x][0];
		return x;
	}

	void insert(char c) {  // 建树
		s[++tot] = c;
		cout<<len[last]<<" ";
		int now = getfail(last);
		//cout<<len[now]<<" ";
		if (!ch[now][c - 'a']) {
			int x = node(len[now] + 2);
			fail[x][0] = ch[getfail(fail[now][0])][c - 'a'];
			for(int i=1;i<=20;++i)
				fail[x][i]=fail[fail[x][i-1]][i-1];
			ch[now][c - 'a'] = x;
		}
		last = ch[now][c - 'a'];
		cnt[last]++;
	}
	const int M=5005;
	pair<int,int> dp[M][M];
	int pos[M];
	void solve(int n,string s){
		clear();
		for(int i=0;i<n;++i){
			insert(s[i]);
			pos[i]=last;
			//cout<<len[last]<<" ";
		}
		for(int L=n-1;L>=0;--L){
			dp[L][L]=make_pair(0,0);
			for(int R=L+1;R<n;++R){
				dp[L][R]=make_pair((int)1e9,(int)1e9);
				int cur=pos[R];
				for(int i=20;i>=0;--i){
					if(len[fail[cur][i]]>=R-L+1)
						cur=fail[cur][i];
				}				
				if(len[cur]&1){
					auto tmp=dp[L][L+len[cur]/2];
					tmp.first++;
					tmp.second+=abs(len[cur]-(R-L+1));
					dp[L][R]=min(dp[L][R],tmp);
				}else {
					auto tmp=dp[L][L+len[cur]/2-1];
					tmp.first++;
					tmp.second+=abs(len[cur]-(R-L+1));
					dp[L][R]=min(dp[L][R],tmp);
				}
			}
		}
		cout<<dp[0][n-1].first<<" "<<dp[0][n-1].second<<endl;
	}

}  // namespace pam
int main(){
	trans['v']='^';
	trans['^']='v';
	int n;
	string s;
	cin>>n>>s;
	pam::solve(n,s);
}


