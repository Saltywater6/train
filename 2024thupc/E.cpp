#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin>>n;
    vector<ll>a(n),b(n),c(n),d(n);
    ll sum=0;
    for(ll i=0;i<n;++i)cin>>a[i];
    for(ll i=0;i<n;++i)cin>>b[i];
    for(ll i=0;i<n;++i)cin>>c[i];
    priority_queue<pair<ll,ll>>que;
    ll free=0;
    for(ll i=0;i<n;++i)
        if(a[i])free+=min(a[i]+c[i],b[i]);
        else if(min(1+c[i],b[i])>0)sum+=min(1+c[i],b[i])-1;
    for(ll i=0;i<n;++i){
        if(a[i]){
            if(free)cout<<free+sum+a[i]+c[i]-min(a[i]+c[i],b[i])<<" ";
            else cout<<a[i]+c[i]<<" ";
        }else {
            if(free){
				if(min(1+c[i],b[i])>0)
					cout<<free+sum+c[i]-min(1+c[i],b[i])+1<<" ";
				else cout<<free+sum+c[i]<<" ";
			}else cout<<"0 ";
        }
    }
    cout<<"\n";
    ll ans=0;
    ll cnt=0;
    while(!que.empty())que.pop();
    for(ll i=0;i<n;++i)
        if(a[i])cnt+=min(a[i]+c[i],b[i]),ans+=c[i]+a[i];
        else que.emplace(min(1+c[i],b[i]),c[i]);
    while(cnt>0&&!que.empty()){
        auto [x,y]=que.top();
        que.pop();
        cnt--,cnt+=x,ans+=y;
    }
    cout<<ans<<endl;

}
