/*
 * GNU C++11   Accepted	  109 ms 800 KB
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[100100], b[100100];

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	int ans = 0, n;
	cin >> n; int tmp_n = n;
	int l = 0, r = 0, k = 0;
	while(tmp_n--){
		cin >> a[k] >> b[k];
		l += a[k];
		r += b[k++];
	}
	int tmp_1 = abs(l-r);
	for(int i = 0; i < n; ++i){
		if(abs((l-a[i]+b[i])-(r-b[i]+a[i])) > tmp_1){
			tmp_1 = abs((l-a[i]+b[i])-(r-b[i]+a[i]));
			ans = i+1;
		}
	}
	cout << ans << endl;
	return 0;
}
