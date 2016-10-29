/*
 * HDOJ-5944	46 MS	1284 K	G++
 */
#include <bits/stdc++.h>

using namespace std;

char s[10100];

int main(){
    int T; scanf("%d", &T);
    while(T--){
        memset(s, 0, sizeof(s));
        scanf("%s", s+1);
        int len = strlen(s+1);
        int ans = 0;
        for(int i = 1; i <= len; ++i){
            for(int j = 2; j <= 100; ++j){
                if(i*j > len || i*j*j > len){
                    break;
                }
                if(s[i] == 'y' && s[i*j] == 'r' && s[i*j*j] == 'x'){
                    ans ++;
                }
                else if(s[i] == 'x' && s[i*j] == 'r' && s[i*j*j] == 'y'){    /// Be careful!
					ans ++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;

}
