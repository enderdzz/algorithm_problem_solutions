/* RMQ + binary_search */
// 67324 KB	1294 ms	GNU G++11 4.9.2

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
int n;
int a[maxn], b[maxn];
/*
template <class T>
struct FenwickTree2D {
    vector< vector<T> > tree;
    int n;
    FenwickTree2D(int n) : n(n) {
        tree.assign(n+1, vector<T>(n+1, LLINF));
    }
    T query(int x, int y){
        T s = LLINF;
        for(int i = x; i > 0; i -= (i&(-i)))//question
            for(int j = y; j > 0; j -= (j&(-j)))
                s = min(s, tree[i][j]);
            return s;
    }
    void update(int x, int y, T v){

        for(int i = x; i <= n; i += (i&(-i)))
            for(int j = y; j <= n; j += (j&(-j)))///there is a trick
                tree[i][j] = min(tree[i][j], v);
    }
    void reset_around(int x, int y){
        for(int i = x; i <= n; i += (i&(-i)))
            for(int j = y; j <= n; j += (j&(-j)))
                tree[i][j] = LLINF;
    }
};
*/
struct RMQ{
    const static int RMQ_size = maxn;
    int n;
    int ArrayMax[RMQ_size][21];
    int ArrayMin[RMQ_size][21];

    void build_rmq(){
        for(int j = 1; (1<<j) <= n; ++j)
        for(int i = 0; i + (1<<j)-1 < n; ++i){
            ArrayMax[i][j] = max(ArrayMax[i][j-1], ArrayMax[i+(1<<(j-1))][j-1]);
            ArrayMin[i][j] = min(ArrayMin[i][j-1], ArrayMin[i+(1<<(j-1))][j-1]);
        }
    }
    int QueryMax(int L, int R){
        int k = 0;
        while( (1<<(k+1)) <= R-L+1)
            k++;
        return max(ArrayMax[L][k], ArrayMax[R-(1<<k)+1][k]);
    }
    int QueryMin(int L, int R){
        int k = 0;
        while( (1<<(k+1)) <= R-L+1)
            k++;
        return min(ArrayMin[L][k], ArrayMin[R-(1<<k)+1][k]);
    }

    void init(int * a, int sz){
        n = sz;
        for(int i = 0; i < n; ++i)
            ArrayMax[i][0] = ArrayMin[i][0] = a[i];
        build_rmq();
    }
}s1, s2;

int main(){
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    for(int j = 0; j < n; ++j)
        cin>>b[j];
    a[n] = 2e9;
    b[n] = -2e9;
    s1.init(a, n+1);
    s2.init(b, n+1);
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] > b[i])
            continue;
        int l = i, r = n, ansl = i;
        while(l <= r){
            int mid = (l+r) / 2;
            if(s1.QueryMax(i, mid) >= s2.QueryMin(i, mid))
                r = mid - 1, ansl = mid;
            else l = mid+1;
        }
        if(s1.QueryMax(i, ansl) > s2.QueryMin(i, ansl))
            continue;
        l = i, r = n;
        int ansr = i;
        while(l <= r){
            int mid = (l+r) / 2;
            if(s1.QueryMax(i, mid) > s2.QueryMin(i, mid))
                r = mid - 1, ansr = mid;
            else l = mid+1;
        }
        ans += ansr-ansl;
    }
    cout << ans << endl;
    return 0;
}
