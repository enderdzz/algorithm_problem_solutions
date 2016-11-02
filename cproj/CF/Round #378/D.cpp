/*
 * GNU C++11	Accepted	249 ms	11800 KB
 */
#include<bits/stdc++.h>

using namespace std;

map< pair<int, int>, pair<int, int> > mp;
int f(int a, int b, int c) {
	return min(a, min(b, c));
}
int main() {
	int n;
	int m = 0, mi, mj, k = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a>b)
			swap(a,b);
		if(b>c)
			swap(b,c);
		if(a>b)
			swap(a,b);
		/// f(a, b, c)
		if(a>m) {  // a is min
			m = a;
			mi = i;
			k = 1;
		}
		if(mp.find({b, c}) != mp.end())
			if(f(mp[{b, c}].first+a, b, c) > m) {
				m = f(mp[{b, c}].first+a, b, c);
				mi = mp[{b, c}].second;
				mj = i;
				k = 2;
			}
		mp[{a, b}] = max(mp[{a, b}], {c, i});
		mp[{a, c}] = max(mp[{a, c}], {b, i});
		mp[{b, c}] = max(mp[{b, c}], {a, i});
	}
	if(k == 1)
		printf("1\n%d\n", mi);
	else
		printf("2\n%d %d\n", mi, mj);
	return 0;
}
