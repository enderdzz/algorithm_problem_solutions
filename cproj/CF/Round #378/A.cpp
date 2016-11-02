/*
 * GNU C++11	Accepted	15 ms	0 KB
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[105];
int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int len = strlen(s);
	int f = 0;
	int last = 0, ans = 0;
	for(int i = 0; i < len; ++i){
		if(!f && (s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')){
			f = 1;
			ans = i+1;
			last = i;
		}
		else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y'){
			ans = max(ans, i-last);
			last = i;
		}
	}
	if(ans == 0) ans = len+1;
	ans = max(len - last, ans);
	cout << ans << endl;
	return 0;
}
