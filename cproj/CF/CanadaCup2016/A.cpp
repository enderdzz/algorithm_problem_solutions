/**
 *  GNU C++11	Accepted	15 ms	300 KB
 **/
#include <bits/stdc++.h>
using namespace std;
int n;
char s[300000];

int main(){
    scanf("%d%s", &n, s);
    int index = 0,ans = 0;
    while(s[index++] == '<')
        ans++;
    index = n-1;
    while(s[index--] == '>')
        ans++;
    cout << ans << endl;
    return 0;

}
/// there is a trick to solve this problem.
/// model is '<<<<<<'+'>********<'+'>>>>>>>'
