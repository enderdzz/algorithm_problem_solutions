/* binary search
 * 4 KB	264 ms GNU G++11 4.9.2
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, ans;

ll cal(ll n){
    ll res = 0LL;
    for(ll i = 2; i*i*i <= n; i++){
        res += n/(i*i*i);
    }
    return res;
}

ll bin_search(){
    ll cur = 1LL<<60;
    while(cur != 0LL){
        ll tmp = cal(n+cur);// to find the (m)|(m-1)'s critical point.
        if(tmp < m){    //-+
            n += cur;   // |
        }               // |
        cur >>= 1LL;    // |
    }                   // V
    n++; // important point!!

    if(cal(n) != m)
        ans = -1;
    else ans = n;
    return ans;
}

int main(){
    cin >> m;

    cout << bin_search() << endl;
    return 0;
}
