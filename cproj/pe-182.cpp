#include<bits/stdc++.h>
using namespace std;
//freopen("1.in","r",stdin);
//freopen("1.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define test freopen("test.txt","r",stdin)
#define maxn 300005
#define eps 1e-9
#define clr(a) memset(a,0,sizeof(a))
typedef long long ll;
const ll mod=1000000007;
const int inf=0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fLL;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
///head***********************************
ll N, phi;

int main()
{
    ll sum = 0;
    ll p = 1009, q = 3643;
    N = p * q;
    phi = (p-1) * (q-1); // 1009 3643
    for(ll e = 11; e < phi; e += 12){ // e+=12 or e++ both OK
        if(gcd(e, phi) != 1){
            continue;
        }
        if(gcd(e-1, p-1) == 2 && gcd(e-1, q-1) == 2){

            sum += e;
        }

    }
    printf("sum = %lld\n", sum);
    return 0;
}
