#include <bits/stdc++.h>
#include <iostream>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for(int (i) = (int)(n)-1; (i) >= 0; (i)--)
#define ll long long
const int mod = 1e9+7;
const int INF = 2e9;
const ll LLINF = 9e16;

using namespace std;
using ld = long double;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
int N, M, P;

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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N>>M>>P;

	vvi key(N, vi(M, 0LL));
	vvii byp(P, vii());
	rep(r, N){
		rep(c, M){
			cin>> key[r][c];
			byp[--key[r][c]].push_back({r, c});
		}
	}

	int NM = max(N, M);
	FenwickTree2D<ll> ft0(NM), ft1(NM), ft2(NM), ft3(NM);
	for(ii v : byp[0]){
		ft0.update(v.first+1, v.second+1, v.first+v.second-v.first-v.second);
		ft1.update(NM-v.first, v.second+1, v.first+v.second+v.first-v.second);
		ft2.update(v.first+1, NM-v.second, v.first+v.second-v.first+v.second);
		ft3.update(NM-v.first, NM-v.second,
				v.first+v.second+v.first+v.second);
	}//Initial Tree

	for(int p = 1; p < P; ++p) {//以后记得写++i
		vi cost(byp[p].size(), 0LL);
		for(size_t i = 0; i < byp[p].size(); ++i){
			int x = byp[p][i].first, y = byp[p][i].second;
			ll v0 = ft0.query(x+1, y+1) + x + y;
			ll v1 = ft1.query(NM-x, y+1) - x + y;
			ll v2 = ft2.query(x+1, NM-y) + x - y;
			ll v3 = ft3.query(NM-x, NM-y) - x - y;
			cost[i] = min(min(v0, v1), min(v2, v3));
		}

		for(ii v : byp[p-1])
			ft0.reset_around(v.first+1, v.second+1),
				ft1.reset_around(NM-v.first, v.second+1),
				ft2.reset_around(v.first+1, NM-v.second),
				ft3.reset_around(NM-v.first, NM-v.second);
		for(size_t i = 0; i < byp[p].size(); ++i) {
			int x = byp[p][i].first, y = byp[p][i].second;
			ft0.update(x+1, y+1, cost[i]-x-y);
			ft1.update(NM-x, y+1, cost[i]+x-y);
			ft2.update(x+1, NM-y, cost[i]-x+y);
			ft3.update(NM-x, NM-y, cost[i]+x+y);
		}
	}
	ii v = *byp[P-1].begin();
	cout<<(v.first+v.second+ft0.query(NM,NM))<<endl;
	return 0;
}
