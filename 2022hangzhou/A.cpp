#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = Exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}

ll gcd(ll a,ll b) {
  if(!b)return a;
  return gcd(b,a%b);
}
int main() {
    int n,mod;
    cin>>n>>mod;
    ll sum=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;sum+=a;
        sum%=mod;
    }
    ll A=n,B=1ll*(1+n)*n/2,x,y;
    ll g=Exgcd(A,B,x,y),k;
    if(sum==0)k=0;
    else if((mod-sum)%g==0)k=(mod-sum)/g;
    else {
      //printf("%lld  %lld %lld\n ",sum,k,g);
        ll GCD=gcd(mod,g);
        ll p=sum/GCD;
        ll AA=mod/GCD,BB=g/GCD;
        ll xx,yy;
        Exgcd(AA,BB,xx,yy);
        //printf("%lld %lld %lld %lld\n",AA,BB,xx,yy);
        k=-yy%mod*p%mod;
    }
    // printf("k=%lld,sum=%lld\n",k,sum);
    printf("%lld\n",((sum+k*g)%mod+mod)%mod);
    x=(x*k%mod+mod)%mod;
    y=(y*k%mod+mod)%mod;
    printf("%lld %lld\n",x,y);
    return 0;
}

