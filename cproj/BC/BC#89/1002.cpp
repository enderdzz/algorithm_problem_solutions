/*
 * HDOJ-5945	249MS	13308K	747 B	G++
 */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000100;
int X, k, t;
int dp[maxn], l, r;
int q[maxn], v[maxn];

void solve(){ ///9 2 1
	for(int i = 0; i < X+1; ++i){
		dp[i] = INT_MAX;
	}
	l = r = 0;
	dp[1] = 0;  // if X==1, then ans = 1
	dp[k] = min(dp[k], 1); //if X == k, then ans = 1
	q[r] = 1+t;
	v[r++] = 1;
	for(int i = 2; i < X+1; ++i){
		while(q[l] < i){ // I still have some questions here.
			l++;
		}
		if(l < r){
			dp[i] = min(dp[i], v[l]);
		}
		if(i%k == 0){   // if k|i, F[i] = min[F[j],F[i/k]], else F[i] = min(F[j]), i-t <= j <= i-1;
			dp[i] = min(dp[i], dp[i/k]+1);
		}
		while(r > l && v[r-1] > dp[i]+1)
			r--;
		q[r] = i + t;
		v[r++] = dp[i] + 1;
	}
	printf("%d\n", dp[X]);
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &X, &k, &t);
		solve();
	}
	return 0;
}
/*
2
9 2 1
11 3 3
*/
